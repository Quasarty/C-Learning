//Автор: Кожевников Андрей
//Задание 704 https://ivtipm.github.io/Programming/Glava21/index21.htm#z704

#include <stdio.h>
#include <stddef.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include "my_unit.h"
#include "matrices.h"

int main(){
    setlocale(LC_ALL, ".UTF8");
    srand(time(NULL)); //< Изменение сида рандома, чтобы рандом был действительно рандомным

    int n = get_natural_num(); //< Размер матриц

    //Выделение памяти под матрицы
    int** matrix_a = create_matrix(n, n); //< Матрица A
    if (matrix_a == NULL){
        puts("Не удалось выделить память");
        return 1;
    }
    int** matrix_b = create_matrix(n, n); //< Матрица B
    if (matrix_b == NULL){
        puts("Не удалось выделить память");
        return 1;
    }
    int** matrix_c = create_matrix(n, n); //< Матрица C
    if (matrix_c == NULL){
        puts("Не удалось выделить память");
        return 1;
    }
    int** matrix_sum = create_matrix(n, n); //< Матрица A+B
    if (matrix_sum == NULL){
            puts("Не удалось выделить память");
            return 1;
    }
    int** matrix_answer = create_matrix(n, n); //< Матрица (A+B)C
    if (matrix_answer == NULL){
            puts("Не удалось выделить память");
            return 1;
    }

    //Рандомное заполнение матриц
    rand_matrix(matrix_a, n, n);
    rand_matrix(matrix_b, n, n);
    rand_matrix(matrix_c, n, n);    

    //Подсчёт суммы матриц
    square_matrices_sum(matrix_sum, matrix_a, matrix_b, n);
    
    //Подсчёт произведения матриц
    square_matrices_mult(matrix_answer, matrix_sum, matrix_c, n);

    //Вывод матриц
    puts("Матрица a");
    print_matrix(matrix_a, n, n);
    puts("Матрица b");
    print_matrix(matrix_b, n, n);
    puts("Матрица c");
    print_matrix(matrix_c, n, n);
    puts("Матрица sum");
    print_matrix(matrix_sum, n, n);
    puts("Матрица answer");
    print_matrix(matrix_answer, n, n);

    //Освобождение памяти
    destroy_matrix(matrix_a, n);
    destroy_matrix(matrix_b, n);
    destroy_matrix(matrix_c, n);
    destroy_matrix(matrix_sum, n);
    destroy_matrix(matrix_answer, n);

    return 0;
}
