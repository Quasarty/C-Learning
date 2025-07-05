//Автор: Кожевников Андрей
//Модуль для работы с файлами

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <wchar.h>

#pragma once

extern const int range; //< Количество чисел в границах рандома
extern const int range_shift; //< Сдвиг в таблице символов
extern const int num_range; //< Количество чисел в границах рандома для гарантированного числа
extern const int max_str_length; //< Максимальная длина строки в файле учеников

/**
 * @brief Генерирует текстовый файл из случайных символов
 * 
 * @param file_name - имя файла
 * @param char_count - количество символов в файле
 * @param guarantee - если true, то гарантиует, что первые два символа - цифры
 * @note Минимальная длина файла - 2 символа
 */
void generate_file(char* file_name, size_t char_count, bool guarantee);


/**
 * @brief Функция считывает два символа из текстового файла и массив символов с ними
 * 
 * @param file_name - имя файла
 * @return char* - массив из двух символов
 */
char* get_two_chars(char* file_name);


/**
 * @brief Процедура сравнивает две строки, содержащих информацию об учениках
 * 
 * @param student_a - строка, содержащая информацию о первом ученике
 * @param student_b - строка, содержащая информацию о втором ученике
 * @return true: если имя и фамилия двух учеников совпадает;
 * @return false: если имя или фамилия двух учеников не совпадает
 */
bool compare_student(wchar_t* student_a, wchar_t* student_b);


/**
 * @brief Процедура сравнивает всех учеников в файле
 * 
 * @param file_name - имя файла
 * @return true: если есть два ученика с одинаковым именем и фамилией
 * @return false: если нету двух учеников с одинаковым именем и фамилией
 */
bool file_compare_students(char* file_name);