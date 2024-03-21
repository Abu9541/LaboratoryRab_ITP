#include <iostream>
#include <forward_list>
using namespace std;

void view(forward_list<int> x){
    for (auto iter = x.begin(); iter != x.end(); ++iter){
        cout << *iter << "  ";
    }
}

int main(){
    forward_list<int> list = {3, -2, 7, 12, 5, 12, -2, -2, 0 ,56, -9, 100};
    view(list);
    cout << endl;
    auto iter = list.begin();
    ++iter;
    for (iter; iter != list.end(); ++iter){
        auto second = list.begin();
        ++second;
        if (*iter == -2 && iter == second){
            list.pop_front();
            iter = list.begin();
        }
    } 
    iter = list.begin();
    auto iter2 = list.begin();
    ++iter;
    ++iter;
    for (iter; iter != list.end(); ++iter){
        if (*iter == -2){
            iter = list.erase_after(iter2);
        }
        else ++iter2;
    }
    view(list);
    return 0;
}