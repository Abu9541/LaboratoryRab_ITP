#include <iostream>
#include <forward_list>
using namespace std;

void view(forward_list<int> x){
    for (auto iter = x.begin(); iter != x.end(); ++iter){
        cout << *iter << "  ";
    }
}

int main(){
    forward_list<int> list = {3, -2, 7, 12, 5, 12, -1, 0 ,56, -9, 100};
    view(list);
    cout << endl;
    auto iter = list.begin();
    for (iter; iter != list.end(); ++iter){
        if (*iter > 10){
             iter = list.emplace_after(iter, 12);
             break;
        }
    }
    view(list);
    return 0;
}
