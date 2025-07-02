//Автор: Кожевников Андрей
//Модуль для работы с динамическими массивами

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

//Директива компилятора, чтобы исключить ошибку двойного включения
#pragma once 

/**
 * @brief Функция выделяет память под динамический массив из целых чисел, а  также зануляет его
 * 
 * @param size - размер динамического массива
 * @return int* - указатель на первый элемент массива
 * @note Если выделить память не удалось, то возвращает NULL
 */
int* create_array(size_t size);


/**
 * @brief Процедура выводит динамический массив из целых чисел
 * 
 * @param array 
 * @param size
 * @note Выводит по 10 элементов в одной строке
 */
void print_array(int* array, size_t size);


/**
 * @brief Процедура для ручного ввода динамического массива чисел
 * 
 * @param[out] array - указатель на первый элемент массива
 * @param[in] size - размер динамического массива
 */
void enter_array(int* array, size_t size);


/**
 * @brief Функция возвращает сумму элементов динамического массива из целых чисел
 * 
 * @param array - указатель на первый элемент массива
 * @param size - размер динамического массива
 * @return int - сумма элементов массива
 */
int sum_array(int* array, size_t size);


/**
 * @brief Функция возвращает сумму элементов динамического массива из целых чисел, начиная с start_index 
 * 
 * @param array - указатель на первый элемент массива
 * @param size - размер динамического массива
 * @param start_index - начальный индекс массива для суммирования
 * @return int  - сумма элементов массива
 * @note Возвращает 0, если start_index > size
 */
int sumfrom_array(int* array, size_t size, size_t start_index);


/**
 * @brief Процедура по возрастанию сортирует динамический массив из целых чисел
 * 
 * @param array - указатель на первый элемент массива
 * @param size - размер динамического массива
 */
void sort_array(int* array, size_t size);
