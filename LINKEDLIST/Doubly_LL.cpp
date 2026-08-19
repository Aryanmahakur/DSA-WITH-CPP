// ===================== DOUBLY LINKED LIST =====================

#include <iostream>
using namespace std;

//------------------------- Node -------------------------

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

//--------------------- Doubly Linked List ----------------------

class DoublyLinkedList {

public:
    Node* head;

    DoublyLinkedList() {
        head = NULL;
    }

    // Insert at Beginning
    void insertAtHead(int val) {

        Node* newNode = new Node(val);

        if(head == NULL){
            head = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // Insert at End
    void insertAtTail(int val) {

        Node* newNode = new Node(val);

        if(head == NULL){
            head = newNode;
            return;
        }

        Node* temp = head;

        while(temp->next)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    // Display Forward
    void displayForward() {

        Node* temp = head;

        while(temp){
            cout << temp->data << " <-> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    // Display Backward
    void displayBackward() {

        if(head == NULL)
            return;

        Node* temp = head;

        while(temp->next)
            temp = temp->next;

        while(temp){
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }

        cout << "NULL" << endl;
    }

    // Search
    bool search(int key){

        Node* temp = head;

        while(temp){

            if(temp->data == key)
                return true;

            temp = temp->next;
        }

        return false;
    }

    // Count Nodes
    int countNodes(){

        int count = 0;

        Node* temp = head;

        while(temp){
            count++;
            temp = temp->next;
        }

        return count;
    }

    // Delete First Node
    void deleteHead(){

        if(head == NULL)
            return;

        Node* temp = head;
f
        head = head->next;

        if(head)
            head->prev = NULL;

        delete temp;
    }

    // Delete Last Node
    void deleteTail(){

        if(head == NULL)
            return;

        if(head->next == NULL){

            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;

        while(temp->next)
            temp = temp->next;

        temp->prev->next = NULL;

        delete temp;
    }

    // Reverse Doubly Linked List
    void reverse(){

        Node* current = head;
        Node* temp = NULL;

        while(current){

            temp = current->prev;
            current->prev = current->next;
            current->next = temp;

            current = current->prev;
        }

        if(temp)
            head = temp->prev;
    }
};

//------------------------- Main -------------------------

int main() {

    DoublyLinkedList list;

    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);

    list.displayForward();
    // 10 <-> 20 <-> 30 <-> NULL

    list.insertAtHead(5);

    list.displayForward();
    // 5 <-> 10 <-> 20 <-> 30 <-> NULL

    list.displayBackward();
    // 30 <-> 20 <-> 10 <-> 5 <-> NULL

    cout << list.search(20) << endl;
    // 1

    cout << list.countNodes() << endl;
    // 4

    list.deleteHead();

    list.displayForward();
    // 10 <-> 20 <-> 30 <-> NULL

    list.deleteTail();

    list.displayForward();
    // 10 <-> 20 <-> NULL

    list.reverse();

    list.displayForward();
    // 20 <-> 10 <-> NULL

    return 0;
}