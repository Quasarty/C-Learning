//Автор: Кожевников Андрей
//Модуль для работы с матрицами

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

//Директива компилятора, чтобы исключить ошибку двойного включения
#pragma once 

/**
 * @brief Функция выделяет память под матрицу, а также зануляет её
 * 
 * @param rows - количество строк матрицы
 * @param cols - количество столбцов матрицы
 * @return int** - указатель на первую строку матрицы
 * @note Если выделить память не удалось, то возвращает NULL
 */
int** create_matrix(size_t rows, size_t cols);


/**
 * @brief Процедура освобождает память, которую занимала матрица
 * 
 * @param matrix - матрица, которую надо освободить
 * @param rows - количество строк матрицы
 */
void destroy_matrix(int** matrix, size_t rows);


/**
 * @brief Процедура выводит матрицу
 * 
 * @param matrix - матрица, которая выводится
 * @param rows - количество строк матрицы
 * @param cols - количествол столбцов матрицы
 */
void print_matrix(int** matrix, size_t rows, size_t cols);


/**
 * @brief Процедура заполняет матрицу случайными числами 
 * 
 * @param[out] matrix - матрица, которая заполняетяс
 * @param[in] rows - количество строк матрицы
 * @param[in] cols - количествол столбцов матрицы
 * @note Числа < 100  
 */
void rand_matrix(int** matrix, size_t rows, size_t cols);


/**
 * @brief Процедура поэлементно складывает две квадратные матрицы и записывает их сумму в матрицу output_matrix
 * 
 * @param[out] output_matrix - матрица, в которую запишется сумма матриц
 * @param[in] matrix_a - матрица для сложения
 * @param[in] matrix_b - матрица для сложения
 * @param[in] size - размер квадтраных матриц
 */
void square_matrices_sum(int** output_matrix, int** matrix_a, int** matrix_b, size_t size);


/**
 * @brief Процедура умножает две квадратные матрицы и записывает их произведение в матрицу output_matrix
 * 
 * @param[out] output_matrix - матрица, в которую запишется произведение матриц
 * @param[in] matrix_a - матрица для умножения
 * @param[in] matrix_b - матрица для умножения
 * @param[in] size - размер квадтраных матриц
 */
void square_matrices_mult(int** output_matrix, int** matrix_a, int** matrix_b, size_t size);


/**
 * @brief Функция возвращает максимальный элемент среди тех, что включены в узор
 * 
 * @param matrix - матрица, где ищется элемент
 * @param size - размер квадратной матрицы
 * @return int - максимальный элемент
 */
int get_max_in_pattern(int** matrix, size_t size);