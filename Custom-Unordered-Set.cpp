#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

class UnorderedSet {
    Node** table;
    int size;

public:
    UnorderedSet(int s) {
        size = s;
        table = new Node*[size];

        for (int i = 0; i < size; i++)
            table[i] = NULL;
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insert(int key) {
        int index = hashFunction(key);

        Node* temp = table[index];

        while (temp) {
            if (temp->data == key)
                return;

            temp = temp->next;
        }

        Node* newNode = new Node(key);
        newNode->next = table[index];
        table[index] = newNode;
    }

    bool search(int key) {
        int index = hashFunction(key);

        Node* temp = table[index];

        while (temp) {
            if (temp->data == key)
                return true;

            temp = temp->next;
        }

        return false;
    }

    void remove(int key) {
        int index = hashFunction(key);

        Node* curr = table[index];
        Node* prev = NULL;

        while (curr) {
            if (curr->data == key) {

                if (prev == NULL)
                    table[index] = curr->next;
                else
                    prev->next = curr->next;

                delete curr;
                return;
            }

            prev = curr;
            curr = curr->next;
        }
    }

    void display() {

        for (int i = 0; i < size; i++) {

            cout << i << " -> ";

            Node* temp = table[i];

            while (temp) {
                cout << temp->data << " ";
                temp = temp->next;
            }

            cout << endl;
        }
    }
};

int main() {

    UnorderedSet st(7);

    st.insert(10);
    st.insert(20);
    st.insert(30);
    st.insert(20);

    st.display();

    cout << st.search(20) << endl;

    st.remove(20);

    st.display();
}