#include <iostream>
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
        cout << "2. Сформировать начальные данные вводом с файла\n";
        cout << "3. Выезд автобуса из парка\n";
        cout << "4. Въезд автобуса в парк\n";
        cout << "5. Вывод информации об автобусах в консоль\n";
        cout << "6. Вывод информации об автобусах в файл\n";
        cout << "7. Удалить данные из массивов\n";
        cout << "8. Выход из программы\n";
        cout << "Введите ваш выбор: ";
        cin >> choice;
        cout << endl;

        switch (choice) {                           
            case 1:
                park.make_start_data();
                break;
            case 2:
                park.make_start_data_from_file();
                break;
            case 3:
                park.departure();
                break;
            case 4:
                park.entry();
                break;
            case 5:
                park.display_data();
                break;
            case 6:
                park.display_data_in_file();
                break;
            case 7:
                park.delete_data();
                break;
            case 8:
                cout << "Выход из программы...\n";
                break;
            default:
                cout << "Неверный выбор. Пожалуйста, введите существующий вариант.\n";
        }
    } while (choice != 8);

    return 0;
}
