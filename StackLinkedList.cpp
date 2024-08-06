#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* top = nullptr;

void Push(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->next = top;
    top = temp;
}

void Pop()
{
    Node* temp;
    if (top == nullptr)
        return;
    temp = top;
    top = top->next;
    delete temp;
}

void Top()
{
    cout << top->data << endl;
}

void IsEmpty()
{
    if (top == nullptr)
    {
        cout << "empty" << endl;
        return;
    }

    cout << "not empty" << endl;
}

void Print(Node* temp)
{
    if (temp == nullptr)
    {
        return;
    }
    cout << temp->data << " ";
    Print(temp->next);
}

int main()
{
    Push(2);
    Push(3);
    Push(4);
    Print(top);
    cout << endl;

    Pop();
    Print(top);
    cout << endl;

    IsEmpty();
}