#pragma once
#include <iostream>
#include <fstream>
#include <string>


class CFile
{
public:
    void Open(std::fstream& file){
        std::string text;
        std::cout << "Введите название файла с добавлением в конец .txt:  ";
        std::cin >> text;
        file.open(text.c_str());
        if (file.is_open()) std::cout << "Файл открыт.\n";
    }
    void Close(std::fstream& file){
        file.close();
        if (!file.is_open()) std::cout << "Файл закрыт.\n";
    }
    void Seek(std::fstream& file){
        char ch;
        std::cout << "Введите символ, который необходимо найти в файле:  ";
        std::cin >> ch;
        if(file.is_open()){
            int index = 1;
            char el;
            while(file >> el){
                if (el == ch) std::cout << "Символ " << ch << " стоит на " << index << "-м месте в файле\n";
                else index++;
            }
        }
        else std::cout << "Файл закрыт!\n";
    }
    void Read(std::fstream& file){
        if (file.is_open()){
            std::string line;
            std::cout << "Содержимое файла:" << std::endl;
            while(getline(file, line)) std::cout << line << std::endl;
        }
        else std::cout << "Файл закрыт!\n";
    }
    void Write(std::fstream& file){
        if (file.is_open()){
            std::string text;
            std::cout << "Введите текст, который хотите добавить в файл:\n";
            getline(std::cin, text);
            file << text;
            std::string line;
            std::cout << "Содержимое файла:" << std::endl;
            while(getline(file, line)) std::cout << line << std::endl;
        }
        else std::cout << "Файл закрыт!\n";
    }
    long GetPosition(std::fstream& file){
        return file.tellg();
    }
    void GetLenght(std::fstream& file){
        if (file.is_open()){
            int lenght = 0;
            char ch;
            while(file >> ch) lenght++;
            std::cout << "Длина файла в символах равна: " << lenght << std::endl;
        }
        else std::cout << "Файл закрыт!";
    }
};

class CMyDataFile: public CFile 
{
public:
    std::fstream m_file;
};