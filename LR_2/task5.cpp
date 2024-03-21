#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void view(ifstream& file) {
    if (file.is_open()) {
        string line;
        while (getline(file, line, '.')) {
            cout << line;
        }
    }
}

int main(){

    ifstream in("a_task5.txt");
    ofstream out("result_task5.txt");
    if (in.is_open() && out.is_open()) {
        string line;
        while (getline(in, line, '.')){
            int count = 0, i = 0, tr = 0;
            for (char ch : line) {
                if (ch == ';') count ++;
                if (count == 4){
                    i++;
                    if ((i == 3 && ch == '7')) tr++;
                    if ((i == 4 && ch == '2')) tr++;
                    if ((i == 5 && ch == '0')) tr++;
                }
            }
            if (tr == 3) out << line;
        }
    } 
    in.close();
    out.close();
    ifstream result("result_task5.txt");
    view(result);
    result.close();
    return 0;

}