#include <iostream>
using namespace std;

#define MAX_SIZE 101
int Stack[MAX_SIZE];
int top = -1;

void IsEmpty()
{
    if (top == -1)
        cout << "empty" << endl;
    else
        cout << "not empty" << endl;
}

void Push(int data)
{
    if (top == MAX_SIZE - 1)
    {
        cout << "ERROR: Stackoverflow" << endl;
        return;
    }
    Stack[++top] = data;
}

void Pop()
{
    if (top == -1)
    {
        cout << "ERROR: Empty stack!" << endl;
        return;
    }
    top--;
}

void Print()
{
    cout << "stack is: ";
    for (int i = 0; i <= top; ++i)
    {
        cout << Stack[i] << " ";
    }
    cout << endl;
}

int main()
{
    Push(2);
    Push(3);
    Push(4);
    Print();

    Pop();
    Print();

    IsEmpty();
}