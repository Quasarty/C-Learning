//Автор: Кожевников Андрей
//Модуль для работы с двухсвязными списками

#include <stdio.h>
#include <stdlib.h>

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
tnode* create_node(float data){
    //Создание нового узла
    tnode* new_node = malloc( sizeof(tnode) );
    if (new_node == NULL)
        return NULL;
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

/**
 * @brief Процедура добавляет новое число к списку с головой head
 * 
 * @param head - голова списка
 * @param data - новое число
 */
void add_to_list(tnode* head, float data){
    tnode* cur_node = head; //< Переменная текущего узла
    tnode* new_node = create_node(data); //< Переменная нового узла
    if (new_node == NULL || cur_node == NULL)
        return;
    
    //Нахождения хвоста
    while (cur_node->next != NULL)
        cur_node = cur_node->next;

    //Связывание хвоста и нового узла
    cur_node->next = new_node;
    new_node->prev = cur_node;
}


/**
 * @brief Процедура выводит весь список
 * 
 * @param head - указатель на голову списка
 */
void print_list(tnode* head){
    if (head == NULL)
        return;

    tnode* cur_node = head;

    //вывод
    while (cur_node != NULL){   
        printf("%.2f ", cur_node->data);
        cur_node = cur_node->next;
    }
    printf("\n");
}


/**
 * @brief Процедура освобождает память от списка
 * 
 * @param head - голова списка
 */
void free_list(tnode* head){
    if (head == NULL)
        return;
    tnode* cur_node = head;
    
    //Освобождение всех узлов, кроме последнего
    while (cur_node->next != NULL){
        cur_node = cur_node->next;
        free(cur_node->prev);
    }
    //Освобождение последнего элемента
    free(cur_node); 
}


/**
 * @brief - Функция возвращает сумму всех элементов списка
 * 
 * @param head - голова списка
 * @return float - сумма всех чисел
 */
float sum_list(tnode* head){
    float sum = 0.0; //< Сумма 
    tnode* cur_node = head; //< Текущий узел

    while (cur_node != NULL){
        sum = sum + cur_node->data;
        cur_node = cur_node->next;
    }

    return sum;
}


/**
 * @brief - Функция возвращает сумму списка по последовательности
 * 
 * @param head - голова списка
 * @return float - сумма чисел
 * @note Последовательность: x1xn + x2xn-1 +...+ xnx1
 */
float pattern_sum_list(tnode* head){
    float sum = 0.0; //< Переменная суммы
    tnode* cur_node = head; //< Переменная текущего узла
    if (cur_node == NULL)
        return sum;

    //Поиск хвоста
    tnode* cur_tail = head; //< Переменная текущего узла с хвоста
    while (cur_tail->next != NULL)
        cur_tail = cur_tail->next;
    
    //Подсчёт суммы
    while (cur_node != NULL){
        sum = sum + cur_node->data * cur_tail->data;
        cur_node = cur_node->next;
        cur_tail = cur_tail->prev;
    }

    return sum;
}
