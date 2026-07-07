#include <iostream>
using namespace std;

class PriorityQueue {
    int data[100];
    int priority[100];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == 100;
    }

    void enqueue(int value, int p) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }

        data[size] = value;
        priority[size] = p;
        size++;

        cout << value << " inserted\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }

        int highest = 0;

        for (int i = 1; i < size; i++) {
            if (priority[i] > priority[highest])
                highest = i;
        }

        cout << "Removed: " << data[highest] << endl;

        for (int i = highest; i < size - 1; i++) {
            data[i] = data[i + 1];
            priority[i] = priority[i + 1];
        }

        size--;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue Empty\n";
            return;
        }

        cout << "Value  Priority\n";
        for (int i = 0; i < size; i++)
            cout << data[i] << "      " << priority[i] << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.enqueue(10, 2);
    pq.enqueue(20, 5);
    pq.enqueue(30, 1);
    pq.enqueue(40, 4);

    pq.display();

    pq.dequeue();

    pq.display();

    return 0;
}