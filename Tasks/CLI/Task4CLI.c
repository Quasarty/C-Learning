//Автор: Кожевников Андрей
//Задание 84б https://ivtipm.github.io/Programming/Glava04/index04.htm#z84

#include <stdio.h>  //< Модуль для ввода/ввывода
#include <locale.h> //< Модуль для установки локали для корректного отображения кириллицы
#include <math.h>   //< Модуль математических фунцкий
#include <string.h>
#include <ctype.h>

const int shift = 48;

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, ".UTF8"); //< Установка локали для корректного отображение кириллицы

    char brief[256] = "Программа возвращает число, высчитанное по формуле sin х + sin x2 + ... + sin xn\nTask4.exe <n> <x>";
    char argbrief[128] = "Task4.exe <n> <x>\nn - натуральное число, x - действительное";

    int n = 0; //< Переменная входного натурального числа
    float x = 0.0; //< Переменная входного действительного числа
    float answer = 0.0; //< Переменная выходного числа

    //Проверка Параметров
    if (argc > 3 || argc <= 2 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0 ){
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
    
    //Считывание x
    if (atof(argv[2]) == 0){
        puts("Некорректный ввод");
        printf("%s\n",argbrief);
        return 1;
    }
    else
        x = atof(argv[2]);


    
        
    float x_pow = 1.0;
    //Расчёт ответа
    for (int i = 1; i <= n; i++)
    {
        x_pow = x_pow * x;
        answer = answer + sin(x_pow);
    }

    //Вывод отвеа
    printf("%d %f\n", n, x);
    printf("Ответ: %.4f", answer);

    return 0;
}