#include <iostream>
#include <fstream>
using namespace std;

struct Footballers {
    char name[100];
    char amplua[100];
    int age;
    int games;
    char date[15];
    int goals;
};

int main(){

    Footballers ftb[]{{"Cristiano Ronaldo", "Attacker", 39, 1081, "13.02.2024", 850},
                      {"Leonel Messi", "Attacker", 37, 915, "13.02.2024", 770},
                      {"Jan Oblak", "Goalkeeper", 35, 613, "13.02.2024", 2}};
    ofstream out("a_task8.txt", ios::binary);
    if (out.is_open()) {
        for (auto& p : ftb) {
            out.write((char*)&p, sizeof(p));
        }
    }
    out.close();
    int m = 0;
    for (auto x : ftb) {
        m = max(m, x.goals);
    }
    for (auto x : ftb) {
        if (m == x.goals) cout << x.name;
    }
    return 0;

}