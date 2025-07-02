//Автор: Кожевников Андрей
//Задание 136е https://ivtipm.github.io/Programming/Glava06/index06.htm#z136

#include <stdio.h>
#include <locale.h>
#include <stddef.h>
#include "my_unit.h"
#include "lists.h"

int main(){
    setlocale(LC_ALL, ".UTF8");

    int n = get_natural_num();  //< Переменная количества чисел
    float num = 0.0; //< Переменная текущего вводимого числа

    //Добавление первого числа
    printf("Введите 1 число: ");
    scanf("%f", &num);
    tnode* head = create_node(num);

    //Добавление остальных чисел
    for (size_t i = 2; i <= n; i++){
        printf("Введите %d число: ", i);
        scanf("%f", &num);
        add_to_list(head, num);
    }

    //Вывод
    print_list(head);
    float sum = sum_list(head); //< Сумма всех элементов
    printf("Сумма: %.2f", sum);

    free_list(head);
    return 0;
}
