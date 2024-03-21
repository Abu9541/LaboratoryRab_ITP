#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ifstream in("a_task3.txt");
    ofstream out_lower("lower_task3.txt");
    ofstream out_upper("upper_task3.txt");
    int count = 0;
    if (in.is_open() && out_lower.is_open() && out_upper.is_open()) {
        char el;
        while (in >> el) {
            if (isdigit(el)) count++;
            else if (islower(el)) out_lower << el << " ";
            else if (isupper(el)) out_upper << el << " ";
        }
    }
    in.close();
    out_lower.close();
    out_upper.close();
    cout << "Количество числовых значений в файле: " << count << endl;
 
    return 0;
}