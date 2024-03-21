#include <iostream>
#include <list>
using namespace std;

void view(list<int> x){
    for (auto iter = x.begin(); iter != x.end(); ++iter){
        cout << *iter << " ";
    }
} 

int main(){
    list<int> numbers = {3, -2, 7, 12, 5, 12, -2, -2, 0 ,56, -9, 100}, endlist;
    view(numbers);
    cout << endl;
    for (auto iter = numbers.begin(); iter != numbers.end(); iter++){
        if (*iter >= 0) endlist.push_back(*iter);
    }
    for (auto iter = endlist.begin(); iter != endlist.end(); iter++){
        endlist.emplace(iter, 25);

    }
    view(endlist);
    return 0;
}