#include <iostream>
#include <fstream>
using namespace std;

int main(){

    int memo[] {15, 12, 13, 79, 18, 96, 13, 4, 6, 19, 0, 2, 17, 3, 14, 77, 66, 33, 51, 12, 33};
    ofstream out1("a_task9.txt", ios::binary);
    if (out1.is_open()) {
        out1.write((char*)memo, sizeof(memo));
    }
    out1.close();
    ifstream in1("a_task9.txt", ios::binary);
    int result[sizeof(memo)/sizeof(int)];
    if (in1.is_open()) {
        in1.read((char*)result, sizeof(memo));
    }
    cout << "До: ";
    for (int i = 0; i < sizeof(result)/sizeof(int); i++) {
        cout << result[i] << " ";
        result[i] = result[i] * 2;
    }
    cout << endl << "После: ";
    in1.close();
    ofstream out2("a_task9.txt", ios::binary);
    if (out2.is_open()) {
        out2.write((char*)result, sizeof(result));
    }
    out2.close();
    ifstream in2("a_task9.txt", ios::binary);
    int result2[sizeof(result)/sizeof(int)];
    if (in2.is_open()) {
        in2.read((char*)result2, sizeof(result));
    }
    for (int x : result2){
        cout << x << " ";
    }
    in2.close();
    return 0;

}