#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int front, rear, size, capacity;

public:
    // Constructor
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    // 1. Insertion (Enqueue)
    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }

        rear++;
        arr[rear] = data;
        size++;
    }

    // 2. Deletion (Dequeue)
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }

        int value = arr[front];
        front++;
        size--;

        return value;
    }

    // 3. Peek (Front Element)
    int peek() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }

        return arr[front];
    }

    // 4. Check if Queue is Empty
    bool isEmpty() {
        return size == 0;
    }

    // 5. Check if Queue is Full
    bool isFull() {
        return size == capacity;
    }

    // 6. Current Size of Queue
    int getSize() {
        return size;
    }

    // 7. Display Queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);

    // Insertion
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    // Peek
    cout << "Front Element: " << q.peek() << endl;

    // Deletion
    cout << "Deleted: " << q.dequeue() << endl;

    q.display();

    // isEmpty
    if (q.isEmpty())
        cout << "Queue is Empty\n";
    else
        cout << "Queue is Not Empty\n";

    // isFull
    if (q.isFull())
        cout << "Queue is Full\n";
    else
        cout << "Queue is Not Full\n";

    // Size
    cout << "Current Size: " << q.getSize() << endl;

    return 0;
}