//Автор: Кожевников Андрей
//Модуль для работы с файлами

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <wchar.h>

const int range = 43; //< Количество чисел в границах рандома
const int range_shift = 48; //< Сдвиг в таблице символов
const int num_range = 10; //< Количество чисел в границах рандома для гарантированного числа
const int max_str_length = 256; //< Максимальная длина строки в файле учеников


/**
 * @brief Генерирует текстовый файл из случайных символов
 * 
 * @param file_name - имя файла
 * @param char_count - количество символов в файле
 * @param guarantee - если true, то гарантиует, что первые два символа - цифры
 * @note Минимальная длина файла - 2 символа
 */
void generate_file(char* file_name, size_t char_count, bool guarantee){
    FILE* file_var = fopen(file_name, "w"); //< Переменная, для работы с файлом
    if (file_var == NULL)
        return;
    
    //Генерация гарантированных двух символов
    if (guarantee){
        fprintf(file_var, "%c", rand() % num_range + range_shift );
        fprintf(file_var, "%c", rand() % num_range + range_shift );
    }
    else
        fprintf(file_var, "%c", rand() % range + range_shift );
        fprintf(file_var, "%c", rand() % range + range_shift );


    //Генерация остальных символов
    for (size_t i = 2; i < char_count; i++)
        fprintf(file_var, "%c", rand() % range + range_shift );

    fclose(file_var);
}


/**
 * @brief Функция считывает два символа из текстового файла и массив символов с ними
 * 
 * @param file_name - имя файла
 * @return char* - массив из двух символов
 */
char* get_two_chars(char* file_name){
    char* chars = calloc(2, sizeof(char)); //< Возвращаемые символы
    //Открытие файла
    FILE* file_var = fopen(file_name, "r");
    if (file_var == NULL)
        return NULL;
        
        
    //Получаем символы
    chars[0] = fgetc(file_var);
    chars[1] = fgetc(file_var); 

    fclose(file_var);
        
    return chars;
        
}


/**
 * @brief Процедура сравнивает две строки, содержащих информацию об учениках
 * 
 * @param student_a - строка, содержащая информацию о первом ученике
 * @param student_b - строка, содержащая информацию о втором ученике
 * @return true: если имя и фамилия двух учеников совпадает;
 * @return false: если имя или фамилия двух учеников не совпадает
 */
bool compare_student(wchar_t* student_a, wchar_t* student_b){
    //Переменные для имени и фамилии сравниваемых учеников
    wchar_t name_a[64], surname_a[64], name_b[64], surname_b[64]; 

    //Считываем имя и фамилию
    swscanf(student_a, L"%ls %ls", name_a, surname_a);
    swscanf(student_b, L"%ls %ls", name_b, surname_b);

    //Сравниваем
    if (wcscmp(name_a, name_b) == 0 && wcscmp(surname_a, surname_b) == 0)
        return true;
    else
        return false;
}


/**
 * @brief Процедура сравнивает всех учеников в файле
 * 
 * @param file_name - имя файла
 * @return true: если есть два ученика с одинаковым именем и фамилией
 * @return false: если нету двух учеников с одинаковым именем и фамилией
 */
bool file_compare_students(char* file_name){
    //Открытие файла
    FILE* file_var = fopen(file_name, "r");
    if (file_var == NULL)
        return false;

    wchar_t str[max_str_length]; //< Текущая рассматриваемая строка 
    wchar_t compare_str[max_str_length]; //< Текущая строка для сравнения

    //Проверяем строки файла
    while (!feof(file_var)){
        //Открываем файл еще раз, но в другую переменную
        FILE* compare_file_var = fopen(file_name, "r");
        if (compare_file_var == NULL){
            fclose(file_var);
            return false;
        }
        
        //Считываем строку
        fgetws(str, max_str_length, file_var);
        //Достигли конца файла, сравнивать не с чем
        if (feof(file_var)){
            fclose(file_var);
            fclose(compare_file_var);
            return false;
        }

        //Перемещаем курсор во второй переменной на одну строку вперед
        fseek(compare_file_var, ftell(file_var), SEEK_SET);

        //Сравниваем каждую последующую строку с текущей
        while(!feof(compare_file_var)){
            //Считываем строку для сравнения
            fgetws(compare_str, max_str_length, compare_file_var);

            //Сравниваем строки
            if (compare_student(str, compare_str)){
                fclose(file_var);
                fclose(compare_file_var);
                return true;
            }
        }

        fclose(compare_file_var);
    }    
    fclose(file_var);
    return false;
    
}