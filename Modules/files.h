//Автор: Кожевников Андрей
//Модуль для работы с файлами

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

#pragma once

extern const int range; //< Количество чисел в границах рандома
extern const int range_shift; //< Сдвиг в таблице символов
extern const int num_range; //< Количество чисел в границах рандома для гарантированного числа

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