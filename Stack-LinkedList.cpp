#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};
class Stack
{
public:
    Node *top;
    Stack()
    {
        top = nullptr;
    };
    void push(int x)
    {

        Node *newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }
    void pop()
    {
        if (top == nullptr)
        {
            return;
        }
        Node *temp = top;
        top = top->next;
        delete temp;
    }
    void peek()
    {
        if (top == nullptr)
        {
            cout << "Stack Empty\n";
            return;
        }
        cout << top->data;
    }
    bool isEmpty()
    {
        return top == nullptr;
    }
    int size()
    {

        Node *curr = top;
        int index = 0;
        while (curr != nullptr)
        {
            index++;
            curr = curr->next;
        }
        return index;
    }
    void rev(){
        Node* curr=top;
    }
    void display()
    {
        Node *curr = top;
        while (curr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
};
int main()
{
    Stack st1;

    st1.push(10);
    st1.push(20);
    st1.push(30);

    st1.display(); // 30 20 10

    cout << "\nSize: " << st1.size();

    cout << "\nTop: ";
    st1.peek();

    st1.pop();

    cout << "\nAfter pop: ";
    st1.display();
}