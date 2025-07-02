//Автор: Кожевников Андрей
//Задание 479 https://ivtipm.github.io/Programming/Glava13/index13.htm#z479

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <locale.h>
#include "files.h"

// #define int num_range = 10



    
    
int main(){
    srand(time(NULL));
    setlocale(LC_ALL, ".UTF8");
        
    generate_file("f.txt", 300, true);
    char* chars = get_two_chars("f.txt");

    int num = 0; 

    printf("Символы: %c %c\n", chars[0], chars[1]);
    if (isdigit( chars[0] ) && isdigit( chars[1] )){
        num = (chars[0]-range_shift)*10 + chars[1]-range_shift;
        printf("Первые два символа - цифры\n");
        if (num % 2 == 0)
            printf("Цифры образуют четное число\n");
    }
    
    printf("%d", num);
        
    free(chars);
}