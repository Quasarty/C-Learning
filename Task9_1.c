//Автор: Кожевников Андрей
//Задание 446 https://ivtipm.github.io/Programming/Glava12/index12.htm#z446

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <locale.h>
#include "my_unit.h"

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

int main(){
    setlocale(LC_ALL, ".UTF8"); //< Установка локали для корректного отображение кириллицы

    int n = get_natural_num(); //< Входная переменная
    
    //Тестировка функции
    assert(prime(1) == false);
    assert(prime(2) == true);
    assert(prime(3) == true);
    assert(prime(4) == false);
    assert(prime(5) == true);
    assert(prime(7) == true);
    assert(prime(67) == true);
    assert(prime(75) == false);
    assert(prime(89) == true);
    assert(prime(97) == true);
    
    print_answer(n);

    return 0;
}