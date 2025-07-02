//Автор: Кожевников Андрей
//Модуль для работы с матрицами

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>


/**
 * @brief Функция выделяет память под матрицу, а также зануляет её
 * 
 * @param rows - количество строк матрицы
 * @param cols - количество столбцов матрицы
 * @return int** - указатель на первую строку матрицы
 * @note Если выделить память не удалось, то возвращает NULL
 */
int** create_matrix(size_t rows, size_t cols){
    // Выделение памяти для строк
    int** matrix = calloc(rows, sizeof(int*));
    // Если выделить память не удалось, то возвращает NULL
    if (matrix == NULL)
        return NULL;
    //Перебор всех строк
    for (size_t i = 0; i < rows; i++){
        // Выделение памяти для столбцов
        matrix[i] = calloc(cols, sizeof(int));
        // Если выделить память не удалось, то возвращает NULL
        if (matrix[i] == NULL){
            return NULL; 
        }
    }
    return matrix; //< Возвращение указателя на первую строку
}


/**
 * @brief Процедура освобождает память, которую занимала матрица
 * 
 * @param matrix - матрица, которую надо освободить
 * @param rows - количество строк матрицы
 */
void destroy_matrix(int** matrix, size_t rows){
    //проверка нул
    //Освобождение каждой строки
    for (size_t i = 0; i < rows; i++)
        free(matrix[i]);

    free(matrix);
}


/**
 * @brief Процедура выводит матрицу
 * 
 * @param matrix - матрица, которая выводится
 * @param rows - количество строк матрицы
 * @param cols - количествол столбцов матрицы
 */
void print_matrix(int** matrix, size_t rows, size_t cols){
    //Перебор строк
    for (size_t i = 0; i < rows; i++){
        //Перебор колонн
        for (size_t j = 0; j < cols; j++)
            printf("%7d", matrix[i][j]);
        //Переход на новую строку
        printf("\n");
    }
}


/**
 * @brief Процедура заполняет матрицу случайными числами 
 * 
 * @param[out] matrix - матрица, которая заполняетяс
 * @param[in] rows - количество строк матрицы
 * @param[in] cols - количествол столбцов матрицы
 * @note Числа < 100
 */
void rand_matrix(int** matrix, size_t rows, size_t cols){
    //Перебор строк
    for (size_t i = 0; i < rows; i++)
        //Перебор колонн
        for (size_t j = 0; j < cols; j++)
            matrix[i][j] = rand() % 100;
}

/**
 * @brief Процедура поэлементно складывает две квадратные матрицы и записывает их сумму в матрицу output_matrix
 * 
 * @param[out] output_matrix - матрица, в которую запишется сумма матриц
 * @param[in] matrix_a - матрица для сложения
 * @param[in] matrix_b - матрица для сложения
 * @param[in] size - размер квадтраных матриц
 */
void square_matrices_sum(int** output_matrix, int** matrix_a, int** matrix_b, size_t size){
    //Перебор строк
    for (size_t i = 0; i < size; i++)
        //Перебор колонн
        for (size_t j = 0; j < size; j++)
            output_matrix[i][j] = matrix_a[i][j] + matrix_b[i][j];
}


/**
 * @brief Процедура умножает две квадратные матрицы и записывает их произведение в матрицу output_matrix
 * 
 * @param[out] output_matrix - матрица, в которую запишется произведение матриц
 * @param[in] matrix_a - матрица для умножения
 * @param[in] matrix_b - матрица для умножения
 * @param[in] size - размер квадтраных матриц
 */
void square_matrices_mult(int** output_matrix, int** matrix_a, int** matrix_b, size_t size){
    //Перебор строк
    for (size_t i = 0; i < size; i++)
        //Перебор колонн
        for (size_t j = 0; j < size; j++){
            int sum = 0; //< Переменная текущего элемента выходной матрицы
            //Вычисление текущего элемента выходной матрицы  
            for (size_t k = 0; k < size; k++)
                sum = sum + matrix_a[i][k] * matrix_b[k][j];

            output_matrix[i][j] = sum;
        }
}


/**
 * @brief Функция возвращает максимальный элемент среди тех, что включены в узор
 * 
 * @param matrix - матрица, где ищется элемент
 * @param size - размер квадратной матрицы
 * @return int - максимальный элемент
 */
int get_max_in_pattern(int** matrix, size_t size){
    int max = 0;
    //Перебор строк
    for (size_t i = 0; i < size; i++){
        //Первая половина строк
        if (i <= (size / 2) - 1)
            //Диапозон столбцов увеличивается
            for (size_t j = 0; j <= i; j++){
                //Сравнение с max
                if (max < matrix[i][j])
                    max = matrix[i][j];
                if (max < matrix[i][size-1-j]) //< Зеркальный номер столбца
                    max = matrix[i][size-1-j];
            }
        //Вторая половина строк
        else
            //Диапозон столбцов уменьшается
            for (size_t j = 0; j < size - i; j++){
                //Сравнение с max
                if (max < matrix[i][j])
                    max = matrix[i][j];
                if (max < matrix[i][size-1-j]) //< Зеркальный номер столбца
                    max = matrix[i][size-1-j];
            }
    }
    
    return max;
}
