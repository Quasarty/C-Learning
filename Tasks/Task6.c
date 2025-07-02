//Автор: Кожевников Андрей
//Задание 339а https://ivtipm.github.io/Programming/Glava10/index10.htm#z339

//TODO ПЕРЕЧИТАТЬ УСЛОВИЕ И ИСПРАВИТЬ
#include <stdio.h>  //< Модуль для ввода/ввывода
#include <locale.h> //< Модуль для установки локали для корректного отображения кириллицы
#include <stddef.h>
#include "arrays.h"

int main() {
    setlocale(LC_ALL, ".UTF8"); //< Установка локали для корректного отображение кириллицы
    
    int n = 5; //< Переменная размера массива
    int* array = NULL; //< Переменная динамического массива чисел 

    //Считывание n
    printf("Введите натуральное число n: ");
    scanf("%d", &n);
    while (n <= 0 ){
        printf("Введите натуральное число n (n>0): ");
        scanf("%d", &n);
    }
    
    //Создание массива
    array = create_array(n);
    //Проверка успешности создания
    if (array == NULL) {
        puts("Не удалось выделить память для массива");
        return 1;
    }

    //Ввод массива
    enter_array(array, n);

    //Сортировка массива по возрастанию
    sort_array(array, n);

    //Создание массива, куда запишутся неповторяющиеся числа 
    int* new_array = create_array(n); //< Переменная нового массива
    //Проверка успешности создания
    if (new_array == NULL) {
        puts("Не удалось выделить память для массива");
        return 1;
    }
    int new_array_size = 0; //< Фактический размер нового массива

    //Добавление в новый массив всех неповторяющихся чисел
    if (array[0] != array[1])
        new_array[new_array_size++] = array[0];
    for (size_t i = 1; i < n-1; i++){
        if (array[i] != array[i+1] && array[i] != array[i-1]){
            new_array[new_array_size++] = array[i];
        }
    }
    if ( n>=2 && (array[n-1] != array[n-2]) )
        new_array[new_array_size++] = array[n-1];

    //Вывод ответа
    puts("Ответ:");
    print_array(new_array, new_array_size);

    //Освобождение памяти
    free(array);
    free(new_array);

    return 0;
}
