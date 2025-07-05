//Автор: Кожевников Андрей
//Задание 70б https://ivtipm.github.io/Programming/Glava03/index03.htm#z70

#include <stdio.h>  //< Модуль для ввода/ввывода
#include <locale.h> //< Модуль для установки локали для корректного отображения кириллицы
#include <assert.h>

/**
 * @brief Возвращает градус, на котором должна быть минутная стрелка, чтобы быть перпендикулярно часово
 * 
 * @param hour - количество часов
 * @param minute - количество минут
 * @return int - градус
 */
int get_target(int hour, int minute){    
    //Определяем минимальный градус и максимальный
    int low_target = (hour * 30 + 90) % 360;
    int high_target = (hour * 30 + 270) % 360;

    if (low_target > high_target){
        low_target = low_target + high_target;
        high_target = low_target - high_target;
        low_target = low_target - high_target;
    }
    
    //Определяем ближайшее
    if ( high_target >= minute*6 && minute*6 > low_target )
        return high_target;
    else
        return low_target;

}

/**
 * @brief Возвращает минимальное количество минут, необходимое, чтобы минутная стрелка стала перпендикулярна часовой
 * 
 * @param hour - текущее количество часов
 * @param minute - текущее количество минут
 * @return int - количество минут
 */
int get_answer(int hour, int minute){
    int target = get_target(hour, minute); //< Переменная целевого градуса
    int answer = 0; //< Переменная ответа

    //Зная изначальный градус и целевой, получаем количество минут, нужных для достижения целевого градуса
    answer = ((target - minute * 6 + 360) % 360) / 6;

    //Если сменился час, то пересчитываем с учетом нового часа
    if (minute + answer >= 60)
        answer = answer + 5;

    return answer;
}

int main() {
    setlocale(LC_ALL, ".UTF8"); //< Установка локали для корректного отображение кириллицы

    int h = 0, m = 0; //< Переменные входных данных
    
    //Считывание h
    printf("Введите h (Количество часов): ");
    scanf("%d", &h);
    while ( !(0 < h) || !(h <= 12) ) {
        printf("Введите h (0 < h <= 12): ");
        scanf("%d", &h);
    }
    
    //Считывание m
    printf("Введите m (Количество минут): ");
    scanf("%d", &m);
    while ( !(0 <= m) || !(m < 60) ) {
        printf("Введите m (0 <= m < 60): ");
        scanf("%d", &m);
    }

    //Тестировка функций
    assert(get_target(3, 45) == 0);
    assert(get_target(3, 20) == 180);
    assert(get_target(8, 37) == 330);
    assert(get_answer(3, 51) == 14);
    assert(get_answer(7, 47) == 3);
    assert(get_answer(2, 47) == 8);

    //Вывод ответа
    printf("Ответ: %d минут", get_answer(h, m));

    return 0;
}
