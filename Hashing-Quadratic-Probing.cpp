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
        int hash = hashFunction(key);
        int index = hash;
        int i = 0;

        while (table[index] != EMPTY && table[index] != DELETED) {
            i++;
            index = (hash + i * i) % size;

            if (i == size) {
                cout << "Hash Table Full\n";
                return;
            }
        }

        table[index] = key;
    }

    // Search
    bool search(int key) {
        int hash = hashFunction(key);
        int index = hash;
        int i = 0;

        while (table[index] != EMPTY) {
            if (table[index] == key)
                return true;

            i++;
            index = (hash + i * i) % size;

            if (i == size)
                break;
        }

        return false;
    }

    // Delete
    void remove(int key) {
        int hash = hashFunction(key);
        int index = hash;
        int i = 0;

        while (table[index] != EMPTY) {
            if (table[index] == key) {
                table[index] = DELETED;
                cout << key << " deleted.\n";
                return;
            }

            i++;
            index = (hash + i * i) % size;

            if (i == size)
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