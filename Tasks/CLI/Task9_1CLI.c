//Автор: Кожевников Андрей
//Задание 446 https://ivtipm.github.io/Programming/Glava12/index12.htm#z446

#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "..\my_unit.h"

/**
 * @brief Выдает ответ для n = num
 * 
 * @param num - число n
 */
void print_answer(int num){
    puts("Числа близнецы:");
    for (size_t i = num; i < 2*num-1; i++){
        if ( prime(i) && prime(i+2) )
            printf("%d %d\n", i, i+2);
    }
}


int main(int argc, char* argv[]){
    setlocale(LC_ALL, ".UTF8"); //< Установка локали для корректного отображение кириллицы

    char brief[256] = "Программа среди чисел n, n+1, ..., 2n выводит все числа-близнецы, т.е. простые числа , разность между которыми равна двум.";
    char argbrief[128] = "Task9_1.exe <n>\nn - натуральное число";

    int n = 0; //< Переменная входного натурального числа
    
    float answer = 0.0; //< Переменная выходного числа

    //Проверка Параметров
    if (argc > 2 || argc <= 1 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0 ){
        puts(brief);
        return 0;
    }

    //Проверка и считывание n
    if (atof(argv[1]) == 0){
        puts("Некорректный ввод");
        printf("%s\n",argbrief);
        return 1;
    }
    else
        n = (int)atof(argv[1]);

    
    print_answer(n);

    return 0;
        
}