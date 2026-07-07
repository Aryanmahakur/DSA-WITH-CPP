#include <iostream>
using namespace std;

// Node of Linked List
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class Queue {
    Node* front;
    Node* rear;
    int size;

public:
    // Constructor
    Queue() {
        front = NULL;
        rear = NULL;
        size = 0;
    }

    // 1. Enqueue (Insertion)
    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        size++;
    }

    // 2. Dequeue (Deletion)
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }

        Node* temp = front;
        int value = temp->data;

        front = front->next;

        // If queue becomes empty
        if (front == NULL)
            rear = NULL;

        delete temp;
        size--;

        return value;
    }

    // 3. Peek
    int peek() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }

        return front->data;
    }

    // 4. isEmpty
    bool isEmpty() {
        return front == NULL;
    }

    // 5. Size
    int getSize() {
        return size;
    }

    // 6. Display
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }

        Node* temp = front;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    Queue q;

    // Insertion
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Queue: ";
    q.display();

    // Peek
    cout << "Front Element: " << q.peek() << endl;

    // Deletion
    cout << "Deleted: " << q.dequeue() << endl;

    cout << "Queue after deletion: ";
    q.display();

    // isEmpty
    cout << "Is Empty: " << (q.isEmpty() ? "Yes" : "No") << endl;

    // Size
    cout << "Size: " << q.getSize() << endl;

    return 0;
}