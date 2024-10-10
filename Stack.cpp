#include <iostream>
#include <stack>
using namespace std;

class Stack
{
public:
    int *arr;
    int size;
    int top;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int n)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = n;
        }
        else
            cout << "Overflow" << endl;
    }

    void pop()
    {
        if (top >= 0)
        {
            cout<<"Element popped:"<<arr[top]<<endl;
            top--;
        }
        else
            cout << "Underflow" << endl;
    }

    int peek()
    {
        if (top >= 0)
            return arr[top];
        else
            cout << "Stack is empty" << endl;
        return -1;
    }

    bool IsEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
};

int main()
{
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.peek() << endl;
    s.pop();
    cout << s.peek() << endl;
    s.pop();
    cout << s.peek() << endl;
    s.pop();
    cout << s.peek() << endl;

    if (s.IsEmpty())
        cout << "Empty" << endl;
    else
        cout << "Not Empty" << endl;

    return 0;
}