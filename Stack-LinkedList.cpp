#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    char data;
    Node *next;

    Node(char val)
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
    }

    void push(char ch)
    {
        Node *newNode = new Node(ch);
        newNode->next = top;
        top = newNode;
    }

    char pop()
    {
        if (top == nullptr)
        {
            return '\0';
        }

        Node *temp = top;
        char ch = temp->data;
        top = top->next;
        delete temp;

        return ch;
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
        int count = 0;
        Node *curr = top;

        while (curr != nullptr)
        {
            count++;
            curr = curr->next;
        }

        return count;
    }

    void rev()
    {
        stack<char> s1;

        while (!isEmpty())
        {
            s1.push(pop());
        }

        while (!s1.empty())
        {
            push(s1.top());
            s1.pop();
        }
    }

    void display()
    {
        Node *curr = top;

        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    bool check(string c)
    {
        stack<char> ch;

        for (char a : c)
        {
            if (a == '(' || a == '{' || a == '[')
            {
                ch.push(a);
            }
            else
            {
                if (ch.empty())
                {
                    return false;
                }

                if ((a == ')' && ch.top() != '(') ||
                    (a == '}' && ch.top() != '{') ||
                    (a == ']' && ch.top() != '['))
                {
                    return false;
                }

                ch.pop();
            }
        }

        return ch.empty();
    }
    
};

int main()
{
   
    Stack st;

    string str = "hello";

    for (char ch : str)
    {
        st.push(ch);
    }

    cout << "Stack: ";
    st.display();

    st.rev();

    cout << "After rev(): ";
    st.display();

    return 0;
}