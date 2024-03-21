#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ifstream in("a1_task2.txt");
    ofstream out("a2_task2.txt");
    if (in.is_open() && out.is_open()) {
        double el;
        while (in >> el) {
            if (el != 0) out << el / 5 << " ";
        }
    }
    in.close();
    out.close();
    return 0;

}