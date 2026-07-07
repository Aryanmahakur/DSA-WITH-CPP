#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *prev, *next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class Deque {
    Node *front, *rear;

public:
    Deque() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    // Insert at Front
    void insertFront(int val) {
        Node *newNode = new Node(val);

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    // Insert at Rear
    void insertRear(int val) {
        Node *newNode = new Node(val);

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    // Delete from Front
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque Underflow\n";
            return;
        }

        Node *temp = front;
        cout << "Deleted: " << temp->data << endl;

        if (front == rear) {
            front = rear = NULL;
        } else {
            front = front->next;
            front->prev = NULL;
        }

        delete temp;
    }

    // Delete from Rear
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque Underflow\n";
            return;
        }

        Node *temp = rear;
        cout << "Deleted: " << temp->data << endl;

        if (front == rear) {
            front = rear = NULL;
        } else {
            rear = rear->prev;
            rear->next = NULL;
        }

        delete temp;
    }

    // Display
    void display() {
        if (isEmpty()) {
            cout << "Deque Empty\n";
            return;
        }

        Node *temp = front;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

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