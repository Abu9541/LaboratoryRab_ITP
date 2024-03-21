#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Business {
    string FIO;
    double price;
    int months;
    int next_months;
};

int main(){

    Business clients[]{{"John Smith", 15350, 6, 5},
                       {"Dana Weldon", 17335.5, 12, 11},
                       {"Cristal Swarowski", 12550, 3, 2},
                       {"Cris Dalton", 9980, 2, 1}};
    for (auto p : clients){
        cout << p.FIO << " " << p.price << " " << p.months << " " << p.next_months << endl;
    }
    cout << endl << endl;
    ofstream out("a_task10.txt", ios::binary);
    if (out.is_open()) {
        for (auto& p : clients) {
            out.write((char*)&p, sizeof(p));
        }
    }
    out.close();
    ifstream in("a_task10.txt", ios::binary);
    Business sale[4];
    if (in.is_open()) {
        int count = 0;
        while (in.read((char*)&sale[count], sizeof(Business))){
            count++;
        }
    }
    for (int i = 0; i < 4; i++) {
        if (sale[i].next_months >= 4) sale[i].price = sale[i].price - (sale[i].price * 7 / 100);
    }
    for (auto p : sale){
        cout << p.FIO << " " << p.price << " " << p.months << " " << p.next_months << endl;
    }
    in.close();
    ofstream ofs("a_task10.txt", ios::binary);
    if (ofs.is_open()) {
        for (auto& p : sale) {
            ofs.write((char*)&p, sizeof(p));
        }
    }
    return 0;

}