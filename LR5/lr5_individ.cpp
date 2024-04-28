#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    Queue<int> intQueue;

    int choice;
    do {
        std::cout << "\nМеню\nВыберите функцию\n";
        std::cout << "1. Добавить элемент в конец очереди\n";
        std::cout << "2. Удалить первый элемент очереди\n";
        std::cout << "3. Вывод первого элемента очереди\n";
        std::cout << "4. Вывод элемнтов очереди\n";
        std::cout << "5. Выход\n";
        std::cout << "Введите ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                int element;
                std::cout << "Введите добавляемый элемент: ";
                std::cin >> element;
                intQueue.enqueue(element);
                break;
            case 2:
                if (!intQueue.isEmpty()) {
                    std::cout << "Удаляемый элемент: " << intQueue.front() << "\n";
                    intQueue.dequeue();
                } else {
                    std::cout << "Очередь пуста. Удаление невозможно.\n";
                }
                break;
            case 3:
                if (!intQueue.isEmpty()) {
                    std::cout << "Первый элемент: " << intQueue.front() << "\n";
                } else {
                    std::cout << "Очередь пуста. Первого элемента нет.\n";
                }
                break;
            case 4:
                intQueue.display();
                break;
            case 5:
                std::cout << "Выход из программы...\n";
                break;
            default:
                std::cout << "Неверный выбор. Пожалуйста, введите существующий вариант.\n";
        }
    } while (choice != 5);

    return 0;
}