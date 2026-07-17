#include <iostream>
using namespace std;

class HashTable {
    int *table;
    int size;

    const int EMPTY = -1;
    const int DELETED = -2;

public:
    HashTable(int s) {
        size = s;
        table = new int[size];

        for (int i = 0; i < size; i++)
            table[i] = EMPTY;
    }

    int hashFunction(int key) {
        return key % size;
    }

    // Insert
    void insert(int key) {
        int index = hashFunction(key);

        while (table[index] != EMPTY && table[index] != DELETED) {
            index = (index + 1) % size;
        }

        table[index] = key;
    }

    // Search
    bool search(int key) {
        int index = hashFunction(key);
        int start = index;

        while (table[index] != EMPTY) {
            if (table[index] == key)
                return true;

            index = (index + 1) % size;

            if (index == start)
                break;
        }

        return false;
    }

    // Delete
    void remove(int key) {
        int index = hashFunction(key);
        int start = index;

        while (table[index] != EMPTY) {
            if (table[index] == key) {
                table[index] = DELETED;
                cout << key << " deleted.\n";
                return;
            }

            index = (index + 1) % size;

            if (index == start)
                break;
        }

        cout << key << " not found.\n";
    }

    // Display
    void display() {
        cout << "\nHash Table:\n";

        for (int i = 0; i < size; i++) {
            cout << i << " -> ";

            if (table[i] == EMPTY)
                cout << "EMPTY";
            else if (table[i] == DELETED)
                cout << "DELETED";
            else
                cout << table[i];

            cout << endl;
        }
    }

    ~HashTable() {
        delete[] table;
    }
};

int main() {
    HashTable ht(7);

    ht.insert(10);
    ht.insert(17);
    ht.insert(24);
    ht.insert(31);

    ht.display();

    cout << "\nSearch 24: ";
    cout << (ht.search(24) ? "Found" : "Not Found") << endl;

    ht.remove(17);

    ht.display();

    cout << "\nSearch 31: ";
    cout << (ht.search(31) ? "Found" : "Not Found") << endl;

    return 0;
}