#pragma once
#include <iostream>
#include <string>
#include <list>
#include <cstring>


//инициализация класса Bus
class Bus {

private:
    std::string surname;       //переменная, хранящая фамилию водителя
    std::string initials;      //переменная, хранящая инициалы водителя
    int route_number;          //переменная, хранящая номер маршрута

public:
    int bus_number;            //переменная, хранящая номер автобуса

    Bus();                    //конструктор класса по-умолчанию

    Bus(int b_num, std::string s_name, std::string init, int r_num){            //конструктор класса
        bus_number = b_num;
        surname = s_name;
        initials = init;
        route_number = r_num;
    }

    void display(){                                     //функция вывода данных об автобусе
        std::cout << "Номер автобуса: " << bus_number << "; инициалы водителя: " << surname << " " << initials << "; номер маршрута: " << route_number << "." << std::endl;
    }
};

//инициализация класса Park
class Park {

private:
    std::list<Bus> in_park;                 //пустой список автобусов, находящихся в парке
    std::list<Bus> on_route;                //пустой список автобусов, находящихся на маршруте

public:
    void make_start_data(){                 //функция формирования начальных данных вводом с клавиатуры
        int num;                            //количество автобусов, которое необходимо добавить в список 
        std::cout << "Введите количество автобусов, данные которых необходимо добавить:  ";
        std::cin >> num;
        std::cout << "Вводите данные по следующему образцу:\nНомер_автобуса Фамилия_водителя Инициалы_водителя Номер_маршрута\nПример: 1 Иванов И.И. 1\n" << std::endl;
        for (int i = 0; i < num; ++i){
            int b_num, r_num;
            std::string s_name, init;
            std::cin >> b_num >> s_name >> init >> r_num;
            Bus object(b_num, s_name, init, r_num);            //создание объекта класса Bus
            in_park.push_back(object);                         //добавление объекта в список автобусов, находящихся в парке
        }
    }

    void departure(){                        //функция имитации выезда автобуса из парка
        int num, count = 0;                  //num - номер автобуса, выезжающего из парка, count - переменная для проверки наличия автобуса с заданным номером в списке
        std::cout << "Введите номер автобуса, который выезжает из парка:  ";
        std::cin >> num;
        auto iter = in_park.begin();          //итератор на начало списка
        for (Bus obj : in_park){
            if (obj.bus_number == num){          //проверка соответствия номеров
                count++;
                on_route.push_back(obj);          //добавление автобуса в список автобусов, находящихся на маршруте
                in_park.erase(iter);              //удаление автобуса из списка автобусов, находящихся в парке
                std::cout << "Автобус номер " << num << " выехал из парка." << std::endl;
                break;
            }
            ++iter;                              //смещение итератора
        }
        if (count == 0){                         //вывод на случай, если автобуса с заданным номером нет в списке; обработка исключения
            std::cout << "Автобуса с номером " << num << " нет в парке!" << std::endl;
        }
    }

    void entry(){                                //функция имитации въезда автобуса в парк
        int num, count = 0;                      //num - номер автобуса, въезжающего в парк, count - переменная для проверки наличия автобуса с заданным номером в списке
        std::cout << "Введите номер автобуса, который въезжает в парк:  ";
        std::cin >> num;
        auto iter = on_route.begin();            //итератор на начало списка
        for (Bus obj : on_route){
            if (obj.bus_number == num){          //проверка соответствия номеров
                count++;
                in_park.push_back(obj);          //добавление автобуса в список автобусов, находящихся в парке
                on_route.erase(iter);            //удаление автобуса из списка автобусов, находящихся на маршруте
                std::cout << "Автобус номер " << num << " въехал в парк." << std::endl;
                break;
            }
            ++iter;                              //смещение итератора
        }
        if (count == 0){                         //вывод на случай, если автобуса с заданным номером нет в списке; обработка исключения
            std::cout << "Автобуса с номером " << num << " нет в списке автобусов, находящихся на маршруте!" << std::endl;
        }
    }

    void display_data(){                         //вывод информации об автобусах
        std::cout << "Сведения об автобусах, находящихся в парке: " << std::endl;
        int count = 1;                           //переменная для нумерации
        for (Bus obj : in_park){
            std::cout << count << ". ";
            obj.display();                        //вывод данных об автобусе из списка
            ++count;
        }
        count = 1;                                //обновление переменной нумерации
        std::cout << std::endl << "Сведения об автобусах, находящихся на маршруте: " << std::endl;
        for (Bus obj : on_route){
            std::cout << count << ". ";
            obj.display();                        //вывод данных об автобусе из списка
            ++count;
        }
    }
};