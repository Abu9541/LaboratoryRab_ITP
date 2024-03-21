#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ifstream in("a_task4.txt");
    int sum = 0, count = 0;
    if (in.is_open()) {
        int i = -1;
        int el;
        while (in >> el) {
            ++i;
            if (i % 2 == 0 && el > 0) {
                sum += el;
                count++;
            }
        }
    }
    in.close();
    cout << sum / count;
 
    return 0;
}