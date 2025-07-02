//Автор: Кожевников Андрей
//Модуль для работы с двухсвязными списками

#include <stdio.h>
#include <stdlib.h>

//Директива компилятора, чтобы исключить ошибку двойного включения
#pragma once 

//Тип данных для узла
struct tnode{
    float data;
    struct tnode* next; 
    struct tnode* prev;
};
typedef struct tnode tnode; //< Более краткое имя для структуры

/**
 * @brief Функция записывает число в новый узел и возвращает указатель на него
 * 
 * @param data - число, хранимое в новом узле
 * @return tnode* - указатель на новый узел
 */
tnode* create_node(float data);


/**
 * @brief Процедура добавляет новое число к списку с головой head
 * 
 * @param head - голова списка
 * @param data - новое число
 */
void add_to_list(tnode* head, float data);


/**
 * 
 * @brief Процедура выводит весь список
 * 
 * @param head - указатель на голову списка
 */
void print_list(tnode* head);


/**
 * @brief Процедура освобождает память от списка
 * 
 * @param head - голова списка
 */
void free_list(tnode* head);


/**
 * @brief - Функция возвращает сумму всех элементов списка
 * 
 * @param head - голова списка
 * @return float - сумма всех чисел
 */
float sum_list(tnode* head);


/**
 * @brief - Функция возвращает сумму списка по последовательности
 * 
 * @param head - голова списка
 * @return float - сумма чисел
 * @note Последовательность: x1xn + x2xn-1 +...+ xnx1
 */
float pattern_sum_list(tnode* head);
