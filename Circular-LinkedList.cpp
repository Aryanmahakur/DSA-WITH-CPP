#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    // Insert at Beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
            head->next = head;
            return;
        }

        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }

        newNode->next = head;
        last->next = newNode;
        head = newNode;
    }

    // Insert at End
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
            head->next = head;
            return;
        }

        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }

        last->next = newNode;
        newNode->next = head;
    }

    // Delete at Beginning
    void deleteAtBeginning() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        // Only one node
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }

        Node* del = head;
        head = head->next;
        last->next = head;

        delete del;
    }

    // Delete at End
    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        // Only one node
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        Node* curr = head;
       

        while (curr->next->next != head) {
          
            curr = curr->next;
        }
       Node* del=curr->next;
          curr->next=del->next;

        delete del;
    }

    // Display
    void display() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};

int main() {
    CircularLinkedList cll;

    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);

    cout << "Initial List: ";
    cll.display();

    cll.insertAtBeginning(5);
    cout << "After Insert at Beginning: ";
    cll.display();

    cll.insertAtEnd(40);
    cout << "After Insert at End: ";
    cll.display();

    cll.deleteAtBeginning();
    cout << "After Delete at Beginning: ";
    cll.display();

    cll.deleteAtEnd();
    cout << "After Delete at End: ";
    cll.display();

    return 0;
}