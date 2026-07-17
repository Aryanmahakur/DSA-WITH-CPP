#include <iostream>
using namespace std;

class Node {
public:
    int key;
    string value;
    Node* next;

    Node(int k, string v) {
        key = k;
        value = v;
        next = NULL;
    }
};

class UnorderedMap {
    Node** table;
    int size;

public:
    UnorderedMap(int s) {
        size = s;
        table = new Node*[size];

        for (int i = 0; i < size; i++)
            table[i] = NULL;
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insert(int key, string value) {

        int index = hashFunction(key);

        Node* temp = table[index];

        while (temp) {

            if (temp->key == key) {
                temp->value = value;
                return;
            }

            temp = temp->next;
        }

        Node* newNode = new Node(key, value);

        newNode->next = table[index];
        table[index] = newNode;
    }

    string search(int key) {

        int index = hashFunction(key);

        Node* temp = table[index];

        while (temp) {

            if (temp->key == key)
                return temp->value;

            temp = temp->next;
        }

        return "Not Found";
    }

    void remove(int key) {

        int index = hashFunction(key);

        Node* curr = table[index];
        Node* prev = NULL;

        while (curr) {

            if (curr->key == key) {

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

                cout << "(" << temp->key << "," << temp->value << ") ";

                temp = temp->next;
            }

            cout << endl;
        }
    }
};

int main() {

    UnorderedMap mp(7);

    mp.insert(101, "Aryan");
    mp.insert(102, "Rahul");
    mp.insert(103, "Aman");

    mp.display();

    cout << mp.search(102) << endl;

    mp.remove(102);

    mp.display();
}