#include <iostream>
using namespace std;

// Node class
class node
{
public:
    int data;
    node *next;

    node(int value)
    {
        data = value;
        next = nullptr;
    }
};

// Singly Linked List
class singlylinkedlist
{
public:
    node *head;

    singlylinkedlist()
    {
        head = nullptr;
    }

    // Destructor
    ~singlylinkedlist()
    {
        while (head != nullptr)
        {
            node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Insert at any position
    void InsertAtAnyPos(int value, int index)
    {
        node *newnode = new node(value);

        // Insert at beginning
        if (index == 1)
        {
            newnode->next = head;
            head = newnode;
            return;
        }

        if (head == nullptr)
        {
            cout << "Invalid Position" << endl;
            delete newnode;
            return;
        }

        node *temp = head;
        int pos = 1;

        while (temp != nullptr && pos < index - 1)
        {
            temp = temp->next;
            pos++;
        }

        if (temp == nullptr)
        {
            cout << "Invalid Position" << endl;
            delete newnode;
            return;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }

    // Delete by position
    void deletebyPos(int index)
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (index == 1)
        {
            node *del = head;
            head = head->next;
            delete del;
            return;
        }

        node *curr = head;
        int pos = 1;

        while (curr->next != nullptr && pos < index - 1)
        {
            curr = curr->next;
            pos++;
        }

        if (curr->next == nullptr)
        {
            cout << "Invalid Position" << endl;
            return;
        }

        node *del = curr->next;
        curr->next = curr->next->next;
        delete del;
    }

    // Search
    void search(int value)
    {
        node *curr = head;

        while (curr != nullptr)
        {
            if (curr->data == value)
            {
                cout << "Data is present" << endl;
                return;
            }

            curr = curr->next;
        }

        cout << "Data is not present" << endl;
    }

    // Reverse list
    void reverse()
    {
        node *prev = nullptr;
        node *curr = head;
        node *nextNode = nullptr;

        while (curr != nullptr)
        {
            nextNode = curr->next;
            curr->next = prev;

            prev = curr;
            curr = nextNode;
        }

        head = prev;
    }

    // Find middle node
    node *findmiddle()
    {
        if (head == nullptr)
            return nullptr;

        node *slow = head;
        node *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // Display list
    void display()
    {
        node *temp = head;

        while (temp != nullptr)
        {
            cout << temp->data;

            if (temp->next != nullptr)
                cout << " -> ";

            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    singlylinkedlist sl;

    sl.InsertAtAnyPos(10, 1);
    sl.InsertAtAnyPos(20, 2);
    sl.InsertAtAnyPos(30, 3);
    sl.InsertAtAnyPos(40, 4);
    sl.InsertAtAnyPos(50, 4);
    sl.InsertAtAnyPos(60, 4);

    sl.display();

    sl.search(10);

    node *mid = sl.findmiddle();
    if (mid != nullptr)
    {
        cout << "Middle: " << mid->data << endl;
    }

    sl.reverse();

    cout << "Reversed: ";
    sl.display();

    return 0;
}