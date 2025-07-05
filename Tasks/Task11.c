//Автор: Кожевников Андрей
//Задание 844е https://ivtipm.github.io/Programming/Glava30/index30.htm#z844

#include <stdio.h>
#include <math.h>

int main(){
    const int weight = 256;
    const int height = 256;
    //.pbm Portable BitMap - формат для черно-белых пиксельных изображений 
    // Подробнее: https://en.wikipedia.org/wiki/Netpbm#File_formats
    FILE* file_var = fopen("Task11.pbm", "w");
    //P1 - аски .pbm файл
    fprintf(file_var, "P1\n");

    //Ширина и высота изображения 
    fprintf(file_var, "%d %d\n", weight, height);
    /*
    Дальше в файле идут 0/1, означающие цвет пикселя (1 - черный)
    Пиксели можно представить в виде матрицы X на Y (все строки матрицы сразу можно записать в одну строку в файле)
    */

    //Цикл по всем y и x
    for (int y = height/2; y > -1*height/2; y--){
        for (float x = -1*weight/2; x < weight/2; x++){
            //Если y в этой точке равен функции, то ставим 1 (или, если это координатная ось)
            if (y == (int)round(cos(x-1) + fabs(x)) || x == 0 || y == 0)
                fputc('1', file_var);
            else
                fputc('0', file_var);
        }
    }
    fclose(file_var);
}