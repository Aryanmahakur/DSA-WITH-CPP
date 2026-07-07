#include <iostream>
using namespace std;

class Deque {
    int arr[100];
    int front, rear;

public:
    Deque() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == 99;
    }

    // Insert at Front
    void insertFront(int x) {
        if (isFull()) {
            cout << "Deque Overflow\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
            arr[front] = x;
        } else {
            for (int i = rear; i >= front; i--)
                arr[i + 1] = arr[i];

            arr[front] = x;
            rear++;
        }
    }

    // Insert at Rear
    void insertRear(int x) {
        if (isFull()) {
            cout << "Deque Overflow\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }

        arr[rear] = x;
    }

    // Delete from Front
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque Underflow\n";
            return;
        }

        cout << "Deleted: " << arr[front] << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            for (int i = front; i < rear; i++)
                arr[i] = arr[i + 1];

            rear--;
        }
    }

    // Delete from Rear
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque Underflow\n";
            return;
        }

        cout << "Deleted: " << arr[rear] << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            rear--;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque Empty\n";
            return;
        }

        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
};

int main() {
    Deque dq;

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertFront(2);

    dq.display();

    dq.deleteFront();
    dq.display();

    dq.deleteRear();
    dq.display();

    return 0;
}