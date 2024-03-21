#include <iostream>
#include <deque>
using namespace std;

void view(deque<int> x){
    auto iter = x.begin();
    for (iter; iter != x.end(); ++iter){
        cout << *iter << "  ";
    }
}

int main(){
    deque<int> queue1 = {3, 4, 5, 6}, queue2 = {1, 15, 3, 12};
    auto p1 = queue1.begin(), p2 = queue1.end(), p3 = queue2.begin(), p4 = queue2.end();
    for (p1; p1 != p2; ++p1){
        queue2.push_back(*p1);
        ++p4;
    }
    --p4;
    cout << "Первая очередь: ";
    view(queue1);
    cout << endl;
    cout << "Вторая очередь: ";
    view(queue2);
    cout << endl;
    cout << *p3 << "  " << *p4 << endl;
    return 0;
}