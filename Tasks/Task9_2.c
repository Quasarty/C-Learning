//Автор: Кожевников Андрей
//Задание 692е https://ivtipm.github.io/Programming/Glava20/index20.htm#z692

#include <stdio.h>
#include <stddef.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include "matrices.h"
#include "my_unit.h"

int main(){
    setlocale(LC_ALL, ".UTF8");
    srand(time(NULL)); //< Изменение сида рандома, чтобы рандом был действительно рандомным

    int n = get_natural_num(); //< Переменная размера матрицы

    //Создание матрицы
    int** matrix = create_matrix(n, n);
    if (matrix == NULL){
        puts("Не удалось выделить память");
        return 1;
    }
   
    //Заполнение матрицы случайными числами
    rand_matrix(matrix, n, n);

    //Поиск максимального элемента, согласно условию
    int max = get_max_in_pattern(matrix, n);

    //Вывод матрицы
    print_matrix(matrix, n, n);

    printf("Ответ: %d", max);
    
    //Освобождение памяти
    destroy_matrix(matrix, n);

    return 0;
}
