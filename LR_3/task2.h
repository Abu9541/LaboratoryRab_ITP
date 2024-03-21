#pragma once
#include <iostream>

class Rectangle
{
public:
    Rectangle() {

     }
    Rectangle(int x_1, int x_2, int y_1, int y_2) {
        x1 = x_1;
        x2 = x_2;
        y1 = y_1;
        y2 = y_2;
    }
    ~Rectangle() {
        std::cout << "Память очищена." << std::endl;
    }
    int x1, y1, x2, y2;
    void info() {
        std::cout << "Координаты прямоугольника в формате x1 x2 y1 y2: " << x1 << " " << x2 << " " << y1 << " " << y2 << std::endl;
    }
    void isSquare() {
        if (x2 - x1 == y2 - y1 || x2 - x1 == y1 - y2) std::cout << "Этот прямоугольник - квадрат." << std::endl;
        else std::cout << "Этот прямоугольник не является квадратом." << std::endl;
    }
};