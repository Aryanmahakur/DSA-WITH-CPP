#include <iostream>
#include <vector>
using namespace std;

class HashTable {


    int hashFunction(int key)
    {
        return key % SIZE;
    }

    void insert(int key)
    {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    bool search(int key)
    {
        int index = hashFunction(key);

        for(int x : table[index])
            if(x==key)
                return true;

        return false;
    }

    void remove(int key)
    {
        int index = hashFunction(key);

        auto &bucket = table[index];

        for(auto it=bucket.begin();it!=bucket.end();it++)
        {
            if(*it==key)
            {
                bucket.erase(it);
                return;
            }
        }
    }

    void display()
    {
        for(int i=0;i<SIZE;i++)
        {
            cout<<i<<" -> ";

            for(int x : table[i])
                cout<<x<<" ";

            cout<<endl;
        }
    }
};

int main()
{
    HashTable ht;

    ht.insert(15);
    ht.insert(25);
    ht.insert(35);
    ht.insert(12);

    ht.display();
}