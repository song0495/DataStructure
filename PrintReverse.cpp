#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head;

void Insert(int data, int n = 1)
{
    Node* temp = new Node;
    temp->data = data;
    if (n == 1)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        Node* prev = head;
        for (int i = 0; i < n - 2; i++)
        {
            prev = prev->next;
        }
        temp->next = prev->next;
        prev->next = temp;
        cout << "在第 " << n << " 位上插入了数字 " << data << endl;
    }
}

void ReversePrint(Node* p)
{
    if (p == nullptr)
    {
        return;
    }
    ReversePrint(p->next);
    cout << p->data << " ";
}

void Print(Node* p)
{
    if (p == nullptr)
    {
        return;
    }
    cout << p->data << " ";
    Print(p->next);
}

int main()
{
    head = nullptr;
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(4);
    Insert(5);

    Print(head);
    cout << endl;
    ReversePrint(head);
}