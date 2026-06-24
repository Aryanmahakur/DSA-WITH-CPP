#include <iostream>
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
        else
        {
            cout << "Stack Not Empty\n";
        }
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
    }
    void find(int x)
    {
        for (int i = 0; i <= top; i++)
        {
            if (x == arr[i])
            {

                cout << x << " is " << arr[i] << " " << "found at index " << i << endl;
                return;
            }
        }
        cout << x << " " << " not found ";
    }
    void max()
    {
        int bigger = 0;
        for (int i = 0; i <= top; i++)
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
        int bigger = INT_MAX;
        for (int i = 0; i <= top; i++)
        {
            if (arr[i] < bigger)
            {
                bigger = arr[i];
            }
        }
        cout << bigger << endl;
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
    void reverse(){
        for(int i=top;i>=0;i--){
           cout<<arr[i]<<" ";
        }
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
    st.display();
    st.find(10);
    st.max();
    st.min();
    st.sum();
    st.reverse();
}