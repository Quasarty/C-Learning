//Автор: Кожевников Андрей
//Задание 11e https://ivtipm.github.io/Programming/Glava01/index01.htm#z11

#include <stdio.h>  //< Модуль для ввода/ввывода
#include <math.h>   //< Модуль математических фунцкий
#include <locale.h> //< Модуль для установки локали для корректного отображения кириллицы

int main() {
    setlocale(LC_ALL, ".UTF8"); //< Установка локали для корректного отображение кириллицы

    float x = 0, y = 0, z = 0;  //< Переменные входных данных
    float a = 0, b = 0;     //< Переменные выходных данных

    //Считывание входных данных
    printf("Введите x, y, z: ");
    scanf("%f %f %f", &x, &y, &z);
    
    //Вычисления
    //fabs - модуль вещественного числа (abs - модуль целого)
    a = ( 1 + pow(sin(x + y), 2) ) / ( 2 + fabs( x - (2*x / ( 1 + pow(x, 2)*pow(y, 2) )) ) );
    b = pow(cos(atan(1 / z)), 2);

    //Вывод ответа
    printf("Ответ: a = %.2f; b = %.2f", a, b);

    //Если программа завершаеся успешно, то она возвращает 0
    return 0;
}
