#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    static const int SIZE = 5;
    vector<int> table[SIZE];

    int hashFunction(int key) {
        return key % SIZE;
    }

public:
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    bool search(int key) {
        int index = hashFunction(key);

        for (int x : table[index]) {
            if (x == key)
                return true;
        }

        return false;
    }

    void remove(int key) {
        int index = hashFunction(key);

        auto &bucket = table[index];

        for (auto it = bucket.begin(); it != bucket.end(); it++) {
            if (*it == key) {
                bucket.erase(it);
                return;
            }
        }
    }

    void display() {
        for (int i = 0; i < SIZE; i++) {
            cout << i << " -> ";

            for (int x : table[i])
                cout << x << " ";

            cout << endl;
        }
    }
};

int main() {
    HashTable ht;

    ht.insert(15);
    ht.insert(25);
    ht.insert(35);
    ht.insert(12);

    ht.display();

    cout << "\nSearch 25: " << (ht.search(25) ? "Found" : "Not Found") << endl;
    cout << "Search 100: " << (ht.search(100) ? "Found" : "Not Found") << endl;

    ht.remove(25);

    cout << "\nAfter removing 25:\n";
    ht.display();

    return 0;
}