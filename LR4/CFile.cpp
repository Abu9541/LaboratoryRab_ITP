#include <iostream>
#include <fstream>
#include "CFile.h"

using namespace std;

int main(){

    int a = 0;
    CMyDataFile my_file;
    my_file.Open(my_file.m_file);
    fstream file("data_copy.txt");
    while (a == 0){
        int num;
        cout << "Выберите один из вариантов:\n1. Закрыть файл\n2. Найти символ в файле\n3. Считать файл\n4. Дописать текст в файл\n5. Получить позицию файла\n6. Получить длину файла" << endl;
        cin >> num;
        while(my_file.m_file.eof()){
            char s;
            my_file.m_file >> s;
            file << s;                 
        }
        switch (num){
            case 1:{
                my_file.Close(my_file.m_file);
                a = 1;
                break;
            }
            case 2:{
                my_file.Seek(file);
                break;
            }
            case 3:{
                my_file.Read(file);
                break;
            }
            case 4:{
                my_file.Write(file);
                break;
            }
            case 5:{
                my_file.GetPosition(file);
                break;
            }
            case 6:{
                my_file.GetLenght(file);
                break;
            }

        }
    }

    return 0;
}