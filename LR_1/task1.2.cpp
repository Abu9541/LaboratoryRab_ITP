#include <iostream>
#include <vector>
#include <string>
using namespace std;

void view(vector<string>& x, vector<int> y){
    for (int i = 0 ; i < x.size() ; i++){
        cout << x[i] << ":  " << y[i] << endl;
    }
}

int main(){

    setlocale(LC_ALL, "RUS");
    vector<string> stack;
    vector<int> stack_h;
    int x;
    cout << "Введите количество гор:  ";
    cin >> x;
    for (int i = 0; i < x; i++){
        string str1;
        int str2;
        cout << "Введите название горы:  ";
        cin >> str1;
        cout << "Введите высоту данной горы:  ";
        cin >> str2;
        stack.push_back(str1);
        stack_h.push_back(str2);
    }
    int sum = 0, count = 0;
    for (int i = 0; i < stack_h.size(); i++){
        sum += stack_h[i];
        count += 1;
    }
    cout << "Средняя высота горы: " << (int)(sum / count) << endl;
    view(stack, stack_h);
    
    return 0;
}
