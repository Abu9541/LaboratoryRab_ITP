#include <iostream>
#include <string>
#include <forward_list>
using namespace std;

void dequeue(forward_list<string>& x){
    x.pop_front();
}

void enqueue(forward_list<string>& x, string el) {
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

void view(forward_list<string> x){
    for (auto i = x.begin(); i != x.end(); ++i){
        cout << *i << "  ";
    }
    cout << endl;
}

int main(){

    forward_list<string> numbers {"fault", "flame", "fee", "bus"};
    view(numbers);
    enqueue(numbers, "one");
    enqueue(numbers, "two");
    enqueue(numbers, "three");
    enqueue(numbers, "four");
    view(numbers);
    dequeue(numbers);
    enqueue(numbers, "five");
    view(numbers);
    int str_lenght = 0;
    for (string str : numbers) str_lenght += str.length();
    cout << "Суммарная длина строк:  " << str_lenght << endl;
    return 0;
}
