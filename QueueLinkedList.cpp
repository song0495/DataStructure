#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;

void Enqueue(int data) 
{
    Node* temp = new Node;
    temp->data = data;
    temp->next = nullptr;
    if (front == nullptr && rear == nullptr) 
    {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

void Dequeue()
{
    Node* temp = front;
    if (front == nullptr) 
    {
        cout << "Queue is Empty" << endl;
        return;
    }
    if (front == rear) 
        front = rear = nullptr;
    else
        front = front->next;

    delete temp; // 防止内存泄漏
    temp = nullptr;
}

int Front() 
{
    if (front == nullptr) 
    {
        cout << "Queue is empty" << endl;
        return 1;
    }
    return front->data;
} 

void Print(Node* temp)
{
    if (temp == nullptr)
        return;
    cout << temp->data << " ";
    Print(temp->next);
}

int main()
{
    Enqueue(2); 
    Enqueue(3); 
    Enqueue(4); 
    Dequeue();  
    Enqueue(5); 
    Print(front);
}