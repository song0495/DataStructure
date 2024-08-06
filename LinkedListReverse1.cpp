#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head;

void Insert(int data, int n)
{
    Node* temp = new Node;
    temp->data = data;
    if (n == 1)
    {
        temp->next = head;
        head = temp;
        return;
    }
    Node* prev = head;
    for (int i = 0; i < n - 2; i++)
    {
        prev = prev->next;
    }
    temp->next = prev->next;
    prev->next = temp;
    cout << "在第 " << n << " 位上插入了数字 " << data << endl;
}

void Print()
{
    Node* temp = head;
    cout << "list: ";
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void Reverse()
{
    Node* prev, * current, * next;
    prev = nullptr;
    current = head;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main()
{
    head = nullptr;
    Insert(1, 1);
    Insert(2, 1);
    Insert(3, 1);
    Insert(4, 1);
    Insert(5, 1);

    Print();
    Reverse();
    Print();
}
