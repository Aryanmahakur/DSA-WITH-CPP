#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class Stack_Array
{
public:
    int arr[100];
    int top;

    Stack_Array()
    {
        top = -1;
    }

    void push(int x)
    {
        if (top == 99)
        {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    void pop()
    {
        if (top < 0)
        {
            cout << "Stack Empty\n";
            return;
        }
        top--;
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "Stack Empty\n";
            return -1;
        }
        return arr[top];
    }

    void isEmpty()
    {
        if (top == -1)
        {
            cout << "Stack Empty\n";
            return;
        }

        cout << "Stack Not Empty\n";
    }

    int size()
    {
        return top + 1;
    }

    void display()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void find(int x)
    {
        for (int i = 0; i <= top; i++)
        {
            if (x == arr[i])
            {
                cout << x << " found at index " << i << endl;
                return;
            }
        }

        cout << x << " not found\n";
    }

    void max()
    {
        if (top == -1)
            return;

        int bigger = arr[0];

        for (int i = 1; i <= top; i++)
        {
            if (arr[i] > bigger)
            {
                bigger = arr[i];
            }
        }

        cout << bigger << endl;
    }

    void min()
    {
        if (top == -1)
            return;

        int smaller = arr[0];

        for (int i = 1; i <= top; i++)
        {
            if (arr[i] < smaller)
            {
                smaller = arr[i];
            }
        }

        cout << smaller << endl;
    }

    void sum()
    {
        int summ = 0;

        for (int i = 0; i <= top; i++)
        {
            summ += arr[i];
        }

        cout << summ << endl;
    }

    void reverse()
    {
        int start = 0;
        int end = top;

        while (start < end)
        {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;

            start++;
            end--;
        }
    }

    void palindrome()
    {
        int start = 0;
        int end = top;

        while (start < end)
        {
            if (arr[start] != arr[end])
            {
                cout << "Not Palindrome\n";
                return;
            }

            start++;
            end--;
        }

        cout << "Palindrome\n";
    }

    bool balanced(string s)
    {
        stack<char> ch;

        for (char a : s)
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

    void sort()
    {
        for (int i = 0; i <= top; i++)
        {
            for (int j = i + 1; j <= top; j++)
            {
                if (arr[i] > arr[j])
                {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    void deletemid()
    {
        if (top == -1)
            return;

        int mid = top / 2;

        for (int i = mid; i < top; i++)
        {
            arr[i] = arr[i + 1];
        }

        top--;
    }
};

int main()
{
    Stack_Array st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    cout << "Stack: ";
    st.display();

    cout << "Top: " << st.peek() << endl;

    cout << "Size: " << st.size() << endl;

    st.isEmpty();

    st.find(30);

    cout << "Maximum: ";
    st.max();

    cout << "Minimum: ";
    st.min();

    cout << "Sum: ";
    st.sum();

    st.reverse();
    cout << "After Reverse: ";
    st.display();

    st.sort();
    cout << "After Sort: ";
    st.display();

    st.deletemid();
    cout << "After Delete Mid: ";
    st.display();

    cout << (st.balanced("{[()]}") ? "Balanced" : "Not Balanced") << endl;

    return 0;
}