#include <iostream>
#include <string>
#include <list>
#include "program.h"

using namespace std;

int main(){

    setlocale(LC_ALL, "Russian");
    Park park;                           //инициализация объекта класса Park

    //Меню
    int choice;                          //переменная для выбора функции

    do {
        cout << "\nМеню\nВыберите функцию\n";
        cout << "1. Сформировать начальные данные вводом с клавиатуры\n";
        cout << "2. Выезд автобуса из парка\n";
        cout << "3. Въезд автобуса в парк\n";
        cout << "4. Вывод информации об автобусах\n";
        cout << "5. Выход из программы\n";
        cout << "Введите ваш выбор: ";
        cin >> choice;
        cout << endl;

        switch (choice) {                           
            case 1:
                park.make_start_data();
                break;
            case 2:
                park.departure();
                break;
            case 3:
                park.entry();
                break;
            case 4:
                park.display_data();
                break;
            case 5:
                cout << "Выход из программы...\n";
                break;
            default:
                cout << "Неверный выбор. Пожалуйста, введите существующий вариант.\n";
        }
    } while (choice != 5);

    return 0;
}
