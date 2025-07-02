//Автор: Кожевников Андрей
//Задание 379б https://ivtipm.github.io/Programming/Glava11/index11.htm#z379

#include <stdio.h>
#include <stddef.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include "my_unit.h"
#include "matrices.h"
#include "arrays.h"

int main(){
    setlocale(LC_ALL, ".UTF8");
    srand(time(NULL)); //< Изменение сида рандома, чтобы рандом был действительно рандомным

    int n = get_natural_num(); //< Кол-во строк
    int m = get_natural_num(); //< Кол-во столбцов

    
    int** matrix = create_matrix(n, m); //< Матрица 
    if (matrix == NULL){
        puts("Не удалось выделить память");
        return 1;
    }

    
    int* array = create_array(m); //< Массив для сумм элементов строк
    
    //Заполнение случайными числами
    rand_matrix(matrix, n, m);

    //Перебор столбцов
    for (size_t j = 0; j < m; j++)
        //Перебор строк
        for (size_t i = 0; i < n; i++)
            //Добавление сумм элементов строк в массив
            array[j] = array[j] + matrix[i][j];
    
    //Вывод
    puts("Матрица");
    print_matrix(matrix, n, m);
    puts("Сумма элеменов:");
    print_array(array, m);

    //Освобождение памяти
    destroy_matrix(matrix, n);
    free(array);
}