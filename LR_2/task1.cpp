#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ifstream in("a_task1.txt");
    int count = 0; 
    float sum = 0;
    if (in.is_open()) {
        float el;
        while (in >> el) {
            if (el == 0) count++;
            if (el < 0) sum += el;
        }
    }
    cout << "Количество нулей в файле: " << count << ". Сумма отрицательных значений файла: " << sum << "." << endl;    
    in.close();
    return 0;
}