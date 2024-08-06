#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head = nullptr;

void Reverse()
{
    if (head == nullptr)
        return;
    
    stack<Node*> StackLinkedList;
    Node* temp = head;

    while (temp != nullptr)
    {
        StackLinkedList.push(temp);
        temp = temp->next;
    }

    temp = StackLinkedList.top();
    head = temp;
    StackLinkedList.pop();

    while (!StackLinkedList.empty())
    {
        temp->next = StackLinkedList.top();
        temp = temp->next;
        StackLinkedList.pop();
    }
    temp->next = nullptr;
}

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
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(4);
    Insert(5);

    Print(head);
    cout << endl;
    Reverse();
    Print(head);
}