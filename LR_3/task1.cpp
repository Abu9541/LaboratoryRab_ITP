#include <iostream>
#include "task1.h"

using namespace std;

int main() {

    setlocale(LC_ALL, "RUS");

    float speed;
    int time;
    cout << "Создание объекта.\nВведите вещественное число - значение скорости объекта в метрах в секунду - ";
    cin >> speed;
    cout << "Введите целое число - время передвижения в минутах - ";
    cin >> time;
    Speed object1(speed, time);
    object1.info();
    object1.distance();
    return 0;

}