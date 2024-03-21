#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void view(ifstream& file) {
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            string text = line;
            cout << text;
        }
    }
}

int main(){

    ifstream in("f_task6.txt");
    ofstream out("g_task6.txt");
    if (in.is_open() && out.is_open()) {
        string line;
        while (getline(in, line)) {
            out << line;
            cout << line << endl << endl;
        }
    } 
    in.close();
    out.close();
    ifstream vout("g_task6.txt");
    view(vout);
    vout.close();
    return 0;

}