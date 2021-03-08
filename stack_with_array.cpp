#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
class Stack
{
    int top;

public:
    int a[MAX];
    Stack()
    {
        top = -1;
    }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

bool Stack::push(int x)
{
    if (top >= MAX - 1)
    {
        cout << "Stack underflow";
        return false;
    }
    else
    {
        a[++top] = x;
        cout << x << " Pushed into the stack";
        return true;
    }
}

int Stack::pop()
{
    if (top < 0)
    {
        cout << "Stack underflow";
        return 0;
    }
    else
    {
        int x = a[top];
        return x;
    }
}
int Stack::peek()
{
    if (top < 0)
    {
        cout << "Stack is empty";
        return 0;
    }
    else
    {
        int x = a[top];
        return x;
    }
}
bool Stack::isEmpty()
{
    return (top < 0);
}
int main()
{

    return 0;
}