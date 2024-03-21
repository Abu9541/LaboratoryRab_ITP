#include <iostream>
#include <forward_list>
using namespace std;

void dequeue(forward_list<float>& x){
    x.pop_front();
}

void enqueue(forward_list<float>& x, float el) {
    if (x.empty()) {
        x.push_front(el);
    } else {
        auto iter = x.before_begin();
        while (next(iter) != x.end()) {
            ++iter;
        }
        x.insert_after(iter, el);
    }
}

void view(forward_list<float> x){
    for (auto i = x.begin(); i != x.end(); ++i){
        cout << *i << "  ";
    }
    cout << endl;
}

int main(){

    forward_list<float> numbers {5.6, 7.3, -2.4, 9.6, 17, 8.3};
    view(numbers);
    enqueue(numbers, -2.1);
    enqueue(numbers, 1.3);
    enqueue(numbers, -1.34);
    enqueue(numbers, 3.3);
    view(numbers);
    dequeue(numbers);
    enqueue(numbers, 2.9);
    view(numbers);
    float sum = 0;
    for (float num : numbers){
        if (num < 0) sum += num;
    };
    cout << "Сумма отрицательных элементов очереди:  " << sum << endl;
    return 0;
}