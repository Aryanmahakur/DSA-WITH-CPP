#include <iostream>
using namespace std;

// Node class representing a single element of the linked list
class node {
public:
    int data;
    node* next;

    node(int value) {
        data = value;
        next = nullptr;
    }
};

// Singly Linked List class
class singlylinkedlist {
public:
    node* head;

    // Constructor
    singlylinkedlist() {
        head = nullptr;
    }

    // Insert a node at the end
    void insertatend(int value) {
        node* newnode = new node(value);

        if (head == nullptr) {
            head = newnode;
            return;
        }

        node* tempnode = head;

        while (tempnode->next != nullptr) {
            tempnode = tempnode->next;
        }

        tempnode->next = newnode;
    }

    // Delete a node with the given value
    void deleteanode(int value) {

        // Empty list
        if (head == nullptr) {
            return;
        }

        // Delete head node
        if (head->data == value) {
            node* del = head;
            head = head->next;
            delete del;
            return;
        }

        // Find node before target node
        node* tempnode = head;

        while (tempnode->next != nullptr &&
               tempnode->next->data != value) {
            tempnode = tempnode->next;
        }

        // Value not found
        if (tempnode->next == nullptr) {
            return;
        }

        // Delete target node
        node* del = tempnode->next;
        tempnode->next = tempnode->next->next;
        delete del;
    }

    // Display the linked list
    void display() {
        node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main() {
    singlylinkedlist sl;

    sl.insertatend(10);
    sl.insertatend(20);
    sl.insertatend(30);
    sl.insertatend(40);
    sl.insertatend(50);

    sl.deleteanode(30);

    sl.display();

    return 0;
}