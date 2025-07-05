//Автор: Кожевников Андрей
//Задание 507г(а) https://ivtipm.github.io/Programming/Glava13/index13.htm#z507

#include <stdio.h>
#include <stdbool.h>
#include "files.h"

int main(){
    bool result = file_compare_students("students.txt");
    if (result)
        puts("Есть ученики с совпадающими именем и фамилией");
    else
        puts("Таких учеников нет");
}

