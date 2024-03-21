#include <iostream>
#include "task2.h"

using namespace std;

int main() {

    setlocale(LC_ALL, "RUS");

    int x1, x2, y1, y2;
    cout << "Создание объекта.\nВведите 4 целых числа - значения координат x1, x2, y1, y2 прямоугольника соответственно - ";
    cin >> x1 >> x2 >> y1 >> y2;
    Rectangle object1(x1, x2, y1, y2);
    object1.info();
    object1.isSquare();
    return 0;

}