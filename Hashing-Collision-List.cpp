#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int x)
    {
        data=x;
        next=NULL;
    }
};

class HashTable
{
    static const int SIZE=10;

    Node* table[SIZE];

public:

    HashTable()
    {
        for(int i=0;i<SIZE;i++)
            table[i]=NULL;
    }

    int hashFunction(int key)
    {
        return key%SIZE;
    }

    void insert(int key)
    {
        int index=hashFunction(key);

        Node* newNode=new Node(key);

        newNode->next=table[index];

        table[index]=newNode;
    }

    bool search(int key)
    {
        int index=hashFunction(key);

        Node* temp=table[index];

        while(temp)
        {
            if(temp->data==key)
                return true;

            temp=temp->next;
        }

        return false;
    }

    void remove(int key)
    {
        int index=hashFunction(key);

        Node* curr=table[index];
        Node* prev=NULL;

        while(curr)
        {
            if(curr->data==key)
            {
                if(prev==NULL)
                    table[index]=curr->next;
                else
                    prev->next=curr->next;

                delete curr;
                return;
            }

            prev=curr;
            curr=curr->next;
        }
    }

    void display()
    {
        for(int i=0;i<SIZE;i++)
        {
            cout<<i<<" -> ";

            Node* temp=table[i];

            while(temp)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }

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

    cout << "\nSearch 25: "
         << (ht.search(25) ? "Found" : "Not Found") << endl;

    ht.remove(25);

    cout << "\nAfter deleting 25:\n";
    ht.display();
}