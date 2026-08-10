// ===================== CIRCULAR SINGLY LINKED LIST =====================

#include <iostream>
using namespace std;

//------------------------- Node -------------------------

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

//------------------ Circular Linked List ----------------

class CircularLinkedList {

public:
    Node* head;

    CircularLinkedList() {
        head = NULL;
    }

    // Insert at Beginning
    void insertAtHead(int val) {

        Node* newNode = new Node(val);

        if(head == NULL){
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;

        while(temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    // Insert at End
    void insertAtTail(int val) {

        Node* newNode = new Node(val);

        if(head == NULL){
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;

        while(temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;s
    }

    // Display
    void display() {

        if(head == NULL){
            cout << "Empty List" << endl;
            return;
        }

        Node* temp = head;

        do{
            cout << temp->data << " -> ";
            temp = temp->next;
        }while(temp != head);

        cout << "(Head)" << endl;
    }

    // Search
    bool search(int key){

        if(head == NULL)
            return false;

        Node* temp = head;

        do{

            if(temp->data == key)
                return true;

            temp = temp->next;

        }while(temp != head);

        return false;
    }

    // Count Nodes
    int countNodes(){

        if(head == NULL)
            return 0;

        int count = 0;

        Node* temp = head;

        do{

            count++;
            temp = temp->next;

        }while(temp != head);

        return count;
    }

    // Delete First Node
    void deleteHead(){

        if(head == NULL)
            return;

        if(head->next == head){

            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;

        while(temp->next != head)
            temp = temp->next;

        Node* del = head;

        head = head->next;

        temp->next = head;

        delete del;
    }

    // Delete Last Node
    void deleteTail(){

        if(head == NULL)
            return;

        if(head->next == head){

            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;

        while(temp->next->next != head)
            temp = temp->next;

        delete temp->next;

        temp->next = head;
    }

};

//------------------------- Main -------------------------

int main() {

    CircularLinkedList list;

    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);

    list.display();
    // 10 -> 20 -> 30 -> (Head)

    list.insertAtHead(5);

    list.display();
    // 5 -> 10 -> 20 -> 30 -> (Head)

    cout << list.search(20) << endl;
    // 1

    cout << list.countNodes() << endl;
    // 4

    list.deleteHead();

    list.display();
    // 10 -> 20 -> 30 -> (Head)

    list.deleteTail();

    list.display();
    // 10 -> 20 -> (Head)

    return 0;
}