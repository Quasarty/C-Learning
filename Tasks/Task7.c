//Автор: Кожевников Андрей
//Задание 269е https://ivtipm.github.io/Programming/Glava08/index08.htm#z269


#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stddef.h>
#include <stdlib.h>
#include <wchar.h>
#include "my_unit.h"


int main(){
    setlocale(LC_ALL, ".UTF8");

    //Считываем n
    int n = get_natural_num();

    //Выделяем память для строки
    wchar_t* str = calloc(n+1, sizeof(wchar_t)); 
    if (str == NULL){
        puts("Не удалось выделить память");
        return 1;
    }

    while (getchar() != '\n'); //< Очистка буфера, чтобы fgetws нормально сработал
    
    //Считываем строку (stdin - глобальная константа стандартого потока для входных данных)
    puts("Введите строчку:");
    fgetws(str, n+1, stdin); 
    // wscanf(L"%ls", str); //< Не используется, так как должна знать количество слов


    puts("Ваша строчка:");
    wprintf(L"%ls\n", str); //< L - указывает, что используются широкие символы
    
    //Выделяем память под новую строку
    wchar_t* new_str = calloc(n+1, sizeof(wchar_t));
    if (new_str == NULL){
        puts("Не удалось выделить память");
        return 1;
    }

    wchar_t* save_p; //< Сохраняет место, на котором находится wcstok
    
    //Разбиваем строчку на токены(слова) при помощи wcstok (аналог strtok_r, но для wchar_t)
    wchar_t* token = wcstok(str, L" ", &save_p);  //< Первый вызов wcstok, первый аргумент str
    //Последующие вызовы wcstok
    while (token != NULL){
        //Проверяем слово и заменяем, если нужно
        if (wcscmp(token, L"это") == 0) //< wcscmp возвращает 0, если строки совпадают
            token = L"то";
        //Образуем новую строку
        wcscat(new_str, token);
        wcscat(new_str, L" ");
        //В последующих вызовах первый аргумент NULL, чтобы wcstok начинал с save_p
        token = wcstok(NULL, L" ", &save_p);
    }
    
    puts("Новая строчка:");
    wprintf(L"%ls\n", new_str);

    free(str);
    free(new_str);

    return 0;
    
}