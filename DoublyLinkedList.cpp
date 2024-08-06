#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

Node* head;

Node* GetNewNode(int data)
{
    Node* NewNode = new Node;
    NewNode->data = data;
    NewNode->prev = nullptr;
    NewNode->next = nullptr;
    return NewNode;
}

void InsertAtHead(int data)
{
    Node* NewNode = GetNewNode(data);
    if (head == nullptr)
    {
        head = NewNode;
        return;
    }
    head->prev = NewNode;
    NewNode->next = head;
    head = NewNode;
}

void InsertAtTail(int data)
{
    Node* NewNode = GetNewNode(data);

    Node* temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = NewNode;
    NewNode->prev = temp;
}

void Print()
{
    Node* temp = head;
    cout << "Forward: ";
    while (temp != nullptr)
    {
        cout << temp->data;
        temp = temp->next;
    }
    cout << endl;
}

void ReversePrint()
{
    Node* temp = head;
    if (temp == nullptr)
        return;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    cout << "Reverse: ";
    while (temp != nullptr)
    {
        cout << temp->data;
        temp = temp->prev;
    }
    cout << endl;
}

int main()
{
    head = nullptr;
    InsertAtHead(2);
    Print();
    ReversePrint();
    InsertAtHead(3);
    Print();
    ReversePrint();
    InsertAtTail(4);
    Print();
    ReversePrint();
}
