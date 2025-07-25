//Автор: Кожевников Андрей
//Модуль для различных функций, нужных для решения задач

#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Функция проверки числа на простоту
 * 
 * @param number - число для проверки
 * @return true - если число простое
 * @return false - если число не простое
 */
bool prime(int number){
    int i = 2; //< Переменная, отвечающая за текущий делитель
    //1 - не простое число
    if (number <= 1)
        return false;

    //Алгоритм проверяет все натуральные числа от 2 до n^(0,5), если среди них нет делителя, то число простое
    //Цикл, работающий пока текущий делитель в границе
    while (i*i <= number){ 
        //Если действительно делитель, то возвращает false
        if (number % i == 0){ 
            return false;
        }
        i++;
    }
    //Если делитель в промежутке не найден, то число простое
    return true;
}

/**
 * @brief Возвращает натуральное число, которое введёт пользователь
 * 
 * @return int - натуральное число
 */
int get_natural_num(){
    int num = 0;
    printf("Введите натуральное число: ");
    scanf("%d", &num);
    while (num <= 0 ){
        printf("Введите натуральное число (больше 0): ");
        scanf("%d", &num);
    }
    return num;
}
