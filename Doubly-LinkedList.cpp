#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

// Doubly Linked List class
class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Insert at beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = tail = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    // Delete from beginning
    void deleteAtBeginning() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;

        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }

        delete temp;
    }

    // Delete from end
    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = tail;

        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete temp;
    }

    // Forward traversal
    void displayForward() {
        Node* curr = head;

        while (curr != nullptr) {
            cout << curr->data << " <-> ";
            curr = curr->next;
        }

        cout << "NULL\n";
    }

    // Backward traversal
    void displayBackward() {
        Node* curr = tail;

        while (curr != nullptr) {
            cout << curr->data << " <-> ";
            curr = curr->prev;
        }

        cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);

    cout << "Forward: ";
    dll.displayForward();

    cout << "Backward: ";
    dll.displayBackward();

    dll.insertAtBeginning(5);

    cout << "\nAfter inserting 5 at beginning:\n";
    dll.displayForward();

    dll.deleteAtBeginning();

    cout << "\nAfter deleting from beginning:\n";
    dll.displayForward();

    dll.deleteAtEnd();

    cout << "\nAfter deleting from end:\n";
    dll.displayForward();

    return 0;
}