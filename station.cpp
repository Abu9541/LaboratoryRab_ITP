#include <iostream>
#include "station.h"

using namespace std;

int main(){

    setlocale(LC_ALL, "Russian");
    Railway railway;                           //инициализация объекта класса Park

    //Меню
    int choice;                          //переменная для выбора функции

    do {
        cout << "\nМеню\nВыберите функцию\n";
        cout << "1. Сформировать начальные данные вводом с клавиатуры\n";
        cout << "2. Сформировать начальные данные вводом с файла\n";
        cout << "3. Вывод информации о поездах в консоль\n";
        cout << "4. Вывод информации о поездах в файл\n";
        cout << "5. Вывод информации о поезде по его номеру\n";
        cout << "6. Вывод информации о поездах по станции их назначения\n";
        cout << "7. Выход из программы\n";
        cout << "Введите ваш выбор: ";
        cin >> choice;
        cout << endl;

        switch (choice) {                           
            case 1:
                railway.make_start_data();
                break;
            case 2:
                railway.make_start_data_from_file();
                break;
            case 3:
                railway.display_data();
                break;
            case 4:
                railway.display_data_in_file();
                break;
            case 5:
                railway.display_train_info();
                break;
            case 6:
                railway.display_station_info();
                break;
            case 7:
                cout << "Выход из программы...\n";
                break;
            default:
                cout << "Неверный выбор. Пожалуйста, введите существующий вариант.\n";
        }
    } while (choice != 7);

    return 0;
}