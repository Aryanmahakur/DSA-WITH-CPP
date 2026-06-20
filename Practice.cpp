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

class CircularLL {
public:
    Node* head = nullptr;

    // Insert at end
    void insert(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* curr = head;
        while (curr->next != head) {
            curr = curr->next;
        }

        curr->next = newNode;
        newNode->next = head;
    }

    // Display
    void display() {
        if (head == nullptr) {
            cout << "Empty\n";
            return;
        }

        Node* curr = head;
        do {
            cout << curr->data << " ";
            curr = curr->next;
        } while (curr != head);

        cout << endl;
    }

    // Delete by value
    void deleteNode(int val) {
        if (head == nullptr) return;

        Node *curr = head, *prev = nullptr;

        // Head node deletion
        if (head->data == val) {
            if (head->next == head) {
                delete head;
                head = nullptr;
                return;
            }

            Node* tail = head;
            while (tail->next != head)
                tail = tail->next;

            tail->next = head->next;
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        do {
            prev = curr;
            curr = curr->next;
        } while (curr != head && curr->data != val);

        if (curr != head) {
            prev->next = curr->next;
            delete curr;
        }
    }
};

int main() {
    CircularLL cll;

    cll.insert(10);
    cll.insert(20);
    cll.insert(30);

    cll.display();

    cll.deleteNode(20);

    cll.display();
}