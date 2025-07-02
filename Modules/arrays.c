//Автор: Кожевников Андрей
//Модуль для работы с динамическими массивами

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Функция выделяет память под динамический массив из целых чисел, а  также зануляет его
 * 
 * @param size - размер динамического массива
 * @return int* - указатель на первый элемент массива
 * @note Если выделить память не удалось, то возвращает NULL
 */
int* create_array(size_t size){ 
    // Выделение памяти и зануление
    int* array = calloc(size, sizeof( int ));
    // Если выделить память не удалось, то возвращает NULL
    if (array == NULL)
        return NULL; 

    return array; //< Возвращение указателя на первый элемент массива
}

/**
 * @brief Процедура выводит динамический массив из целых чисел
 * 
 * @param array - указатель на первый элемент массива
 * @param size - размер динамического массива
 * @note Выводит по 10 элементов в одной строке
 */
void print_array(int* array, size_t size){
    // Цикл, выводящий все элементы массива
    for (size_t i = 0; i < size; i++){
        printf("%5d ", array[i]);
        // Каждые 10 элементов переход на новую строку
        if ((i + 1) % 10 == 0)
            printf("\n");
    }
    printf("\n");
}

/**
 * @brief Процедура для ручного ввода динамического массива из целых чисел
 * 
 * @param[out] array - указатель на первый элемент массива
 * @param[in] size - размер динамического массива
 */
void enter_array(int* array, size_t size){
    for (size_t i = 0; i < size; i++){
        printf("Введите %d элемент: ", i+1);
        scanf("%d", &array[i]);
    }
}

/**
 * @brief Функция возвращает сумму элементов динамического массива из целых чисел
 * 
 * @param array - указатель на первый элемент массива
 * @param size - размер динамического массива
 * @return int - сумма элементов массива
 */
int sum_array(int* array, size_t size){
    int sum = 0; 
    for (size_t i = 0; i < size; i++)
        sum = sum + array[i];
    return sum;
}

/**
 * @brief Функция возвращает сумму элементов динамического массива из целых чисел, начиная с start_index 
 * 
 * @param array - указатель на первый элемент массива
 * @param size - размер динамического массива
 * @param start_index - начальный индекс массива для суммирования
 * @return int  - сумма элементов массива
 * @note Возвращает 0, если start_index > size
 */
int sumfrom_array(int* array, size_t size, size_t start_index){
    if (start_index > size)
        return 0; 
    int sum = 0;
    for (size_t i = start_index; i < size; i++)
        sum = sum + array[i];
    return sum;
}

/**
 * @brief Процедура по возрастанию сортирует динамический массив из целых чисел
 * 
 * @param array - указатель на первый элемент массива
 * @param size - размер динамического массива
 */
void sort_array(int* array, size_t size){
    //Сортировка
    for (size_t i = 0; i < size-1; i++)
        for (size_t j = i; j < size; j++)
            //Обмен элементов
            if (array[i] > array[j]){
                int temp = array[i]; //< Временная переменная, для обмена i и j элементов
                array[i] = array[j];
                array[j] = temp;
            }
}

