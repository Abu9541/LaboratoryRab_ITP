#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <set>


//инициализация класса Bus
class Train {

private:
    std::string station;       //переменная, хранящая станцию назначения
    int time;                  //переменная, хранящая время отправления в минутах с момента начала дня
    int train_number;          //переменная, хранящая номер поезда

public:
    Train();                    //конструктор класса по-умолчанию

    Train(int t_num, std::string s, int t){            //конструктор класса
        train_number = t_num;
        station = s;
        time = t;
    }

    void display(){                                     //функция вывода данных о поезде
        std::cout << "Номер поезда: " << train_number << "; станция назначения: " << station << "; время отправления: " << time/60 << ":";
        if (time%60 < 10) std::cout << 0;
        std::cout << time%60 << "." << std::endl;
    }

    int get_train_number(){                       //функция возвращает номер поезда
        return train_number;
    }

    std::string get_station(){                   //функция возвращает станцию назначения
        return station;
    }

    int get_time(){                              //функция возвращает время отправления
        return time;
    }
};

//инициализация класса Park
class Railway {

private:
    std::vector<Train> list;                 //пустой список поездов

public:
    void make_start_data(){                 //функция формирования начальных данных вводом с клавиатуры
        int num;                            //количество поездов, которое необходимо добавить в список 
        std::cout << "Введите количество поездов, данные которых необходимо добавить:  ";
        std::cin >> num;
        std::cout << "Вводите данные по следующему образцу:\nНомер_поезда Станция_назначения Время_отправления_в_минутах\nПример: 1 Ставрополь 540\n" << std::endl;
        for (int i = 0; i < num; ++i){
            int t_num, t;
            std::string s;
            std::cin >> t_num >> s >> t;
            Train object(t_num, s, t);            //создание объекта класса Train
            list.push_back(object);             //добавление объекта в список поездов
        }
        std::cout << "Данные приняты." << std::endl;
    }

    void make_start_data_from_file(){       //функция формирования начальных данных вводом из файла 
        std::string name_of_file;           //переменная-название файла
        std::cout << "Расположите текстовый документ в папку с файлами программы.\nВажно: информация в текстовом документе должна быть представлена в следуюем виде: Номер_поезда Станция_назначения Время_отправления_в_минутах. Например: 1 Ставрополь 540.\nВведите название файла с добавлением .txt в конец названия файла: " << std::endl;
        std::cin >> name_of_file;
        std::ifstream file(name_of_file.c_str());     //открыть файл
        if (file.is_open()){
            int t_num, t;
            std::string s;
            while (file >> t_num >> s >> t){
                Train object(t_num, s, t);      //инициализация объекта класса Train
                list.push_back(object);                  //добавление объекта в вектор
            }
            file.close();                   //закрытие файла
            std::cout << "Данные приняты." << std::endl;
        }
        else{
            std::cout<<"Файл невозможно открыть. Возможно, вы ввели некорректное имя файла!" << std::endl;  //обработка исключения
        }
    }

    void display_data(){                         //вывод информации о поездах
        std::cout << "Сведения о поездах: " << std::endl;
        int count = 1;
        if (list.empty()) std::cout << "Список пуст!" << std::endl;                           //переменная для нумерации
        for (Train obj : list){
            std::cout << count << ". ";
            obj.display();                        //вывод данных о поезде из списка
            ++count;
        }
    }

    void display_data_in_file(){                //вывод данных в файл
        std::ofstream file("information.txt");         //инициализация файла для вывода данных
        if (file.is_open()){
            std::cout << "Информация выведена в файл information.txt" << std::endl;
            file << "Сведения о поездах: " << std::endl;
            int count = 1;                           //переменная для нумерации
            if (list.empty()) file << "Список пуст!" << std::endl;
            for (Train obj : list){
                file << count << ". ";
                file << "Номер поезда: " << obj.get_train_number() << "; станция назначения: " << obj.get_station() << "; время отправления: " << obj.get_time()/60 << ":";
                if (obj.get_time()%60 < 10) file << 0;
                file << obj.get_time()%60 << "." << std::endl;
                ++count;
            }
        }
        else{
            std::cout << "Невозможно создать файл! Попробуйте снова." << std::endl;               //обработка исключения
        }
    }

    void display_train_info(){                                                                   //функция вывода информации о поезде по его номеру
        bool flag = false;
        int num;                                                  //номер поезда
        std::cout << "Введите номер поезда, информацию о котором вы хотите получить:  ";
        std::cin >> num;
        for (Train obj : list){
            if (obj.get_train_number() == num) {
                obj.display();
                flag = true;
            }
        }
        if (!flag) std::cout << "Поезда с номером " << num << " нет в списке поездов!" << std::endl;           //обработка исколючения
    }

    void display_station_info(){                                                  //функция вывода информации о поездах по станции их назначения
        bool flag = false;
        int num;                                     //номер станции в списке
        std::vector<std::string> stations;
        for (Train obj : list){
            stations.push_back(obj.get_station());
        }
        std::set<std::string> st(stations.begin(), stations.end());
        std::cout << "Станции назначения: " << std::endl;
        int count = 1;
        for (std::string str : st){
            std::cout << count << ". " << str << std::endl;
            ++count;
        }
        std::cout << "Введите номер станции назначения, чтобы получить информацию о поездах, отправляющихся туда:  ";
        std::cin >> num;
        std::cout << std::endl << "Поезда, отправляющиеся по данному маршруту: " << std::endl;
        int a = 1;
        std::string station;
        for (std::string name : st){
            if (a == num) station = name;
            ++a;
        }
        for (Train obj : list){
            if (obj.get_station() == station){
                obj.display();
                flag = true;
            }
        }
        if (!flag) std::cout << "Поездов, отправляющихся по данному маршруту, нет в списке поездов!" << std::endl;              //обработка исколючения
    }
};