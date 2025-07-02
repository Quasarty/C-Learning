//Автор: Кожевников Андрей
//Модуль для работы с файлами

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

const int range = 43; //< Количество чисел в границах рандома
const int range_shift = 48; //< Сдвиг в таблице символов
const int num_range = 10; //< Количество чисел в границах рандома для гарантированного числа

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
    //Открытие файал
    FILE* file_var = fopen(file_name, "r");
    if (file_var == NULL)
        return NULL;
        
        
    //Получаем символы
    chars[0] = fgetc(file_var);
    chars[1] = fgetc(file_var); 

    fclose(file_var);
        
    return chars;
        
}