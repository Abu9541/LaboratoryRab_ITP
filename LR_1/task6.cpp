#include <iostream>
#include <list>
using namespace std;

void view(list<int> x){
    for (auto iter = x.begin(); iter != x.end(); ++iter){
        cout << *iter << "  ";
    }
}

int main(){
    list<int> numbers = {12, 17, 13, 5, -7, 12, 4, -4, 5, -3}, endlist;
    view(numbers);
    cout << endl;
    int count = 0;
    int *p {&numbers.front()};
    for (auto iter = numbers.begin(); iter != numbers.end(); ++iter){
        if (*iter % 2 == 0){
            endlist.push_back(*iter);
            ++count;
        }
    }
    int *p1 {&endlist.front()};
    if (count == 0) cout << "nil" << endl;
    else view(endlist);
    return 0;
}