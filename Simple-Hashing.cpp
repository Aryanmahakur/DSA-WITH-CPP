#include <iostream>
using namespace std;

class HashTable {

    static const int SIZE = 10;
    int table[SIZE];

public:

    HashTable()
    {
        for(int i=0;i<SIZE;i++)
            table[i]=-1;
    }

    int hashFunction(int key)
    {
        return key % SIZE;
    }

    void insert(int key)
    {
        int index = hashFunction(key);

        table[index]=key;
    }

    bool search(int key)
    {
        int index = hashFunction(key);

        return table[index]==key;
    }

    void remove(int key)
    {
        int index = hashFunction(key);

        if(table[index]==key)
            table[index]=-1;
    }

    void display()
    {
        cout<<"Hash Table\n\n";

        for(int i=0;i<SIZE;i++)
        {
            cout<<i<<" -> "<<table[i]<<endl;
        }
    }
};

int main()
{
    HashTable ht;

    ht.insert(15);
    ht.insert(22);
    ht.insert(37);

    ht.display();

    cout<<"\nSearching 22 : ";

    if(ht.search(22))
        cout<<"Found";
    else
        cout<<"Not Found";

    ht.remove(22);

    cout<<"\n\nAfter Deletion\n\n";

    ht.display();
}