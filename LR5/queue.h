#pragma once
#include <iostream>
#include <vector>

template <typename T>
class Queue {
private:
    std::vector<T> elements;

public:
    void enqueue(const T& element) {
        elements.push_back(element);
    }

    void dequeue() {
        if (!isEmpty()) {
            elements.erase(elements.begin());
        }
    }

    T& front() {
        return elements.front();
    }

    bool isEmpty() const {
        return elements.empty();
    }

    void display(){
        for (int i = 0; i < elements.size(); ++i) std::cout << elements[i] << std::endl;
    }
};