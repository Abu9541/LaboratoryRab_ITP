#pragma once
#include <iostream>

class Speed
{
public:
    Speed(double sp, int t) {
    speed = sp;
    time = t;
    }
    double speed;   //скорость движения м/сек
    int time;       //время передвижения в минутах
    void info() {
        std::cout << "Скорость передвижения " << speed << " м/сек. Время передвижения " << time << " мин. " << std::endl;
    }
    void distance() {
        std::cout << "Пройденное расстояние - " << (float)(speed * time * 60) << " м." << std::endl;
    }
};