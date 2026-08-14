// ===================== SINGLY LINKED LIST =====================

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

//--------------------- Linked List ----------------------

class LinkedList {

public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    // Insert at Beginning
    void insertAtHead(int val) {

        Node* newNode = new Node(val);

        newNode->next = head;
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
    }

    // Display
    void display() {

        Node* temp = head;

        while(temp){
            cout << temp->data << " -> ";
            temp = temp->next;
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

        head = head->next;

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

        while(temp->next->next)
            temp = temp->next;

        delete temp->next;

        temp->next = NULL;
    }

    // Reverse Linked List
    void reverse(){

        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while(curr){

            next = curr->next;

            curr->next = prev;

            prev = curr;

            curr = next;
        }

        head = prev;
    }

};

//------------------------- Main -------------------------

int main() {

    LinkedList list;

    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);

    list.display();
    // 10 -> 20 -> 30 -> NULL

    list.insertAtHead(5);

    list.display();
    // 5 -> 10 -> 20 -> 30 -> NULL

    cout << list.search(20) << endl;
    // 1

    cout << list.countNodes() << endl;
    // 4

    list.deleteHead();

    list.display();
    // 10 -> 20 -> 30 -> NULL

    list.deleteTail();

    list.display();
    // 10 -> 20 -> NULL

    list.reverse();

    list.display();
    // 20 -> 10 -> NULL

    return 0;
}