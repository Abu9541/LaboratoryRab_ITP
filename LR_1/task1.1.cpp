#include <iostream>
#include <deque>
using namespace std;

void view(deque<int> x){
    for (int i = 0; i < x.size(); ++i){
        cout << x[i] << "  ";
    }
}

int main(){
    
    deque <int> q;
    int n;
    int count = 0;
    cout << "Введите количество элементов в деке:  ";
    cin >> n;
    cout << endl;
    for (int i = 0; i < n; ++i){
        int x;
        cin >> x;
        q.push_back(x);
        if (x > 0) count++;
    }
    view(q);
    cout << endl << count;
    
    return 0;
}
