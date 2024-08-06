#include<iostream>
using namespace std;
#define MAX_SIZE 10

class Queue
{
private:
    int A[MAX_SIZE]; // 循环数组
    int front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool IsEmpty()
    {
        return (front == -1 && rear == -1);
    }

    bool IsFull()
    {
        return (rear + 1) % MAX_SIZE == front ? true : false;
    }

    void Enqueue(int x)
    {
        cout << "Enqueue " << x << " \n";
        if (IsFull())
        {
            cout << "Queue is Full\n";
            return;
        }
        if (IsEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
        }
        A[rear] = x;
    }

    void Dequeue()
    {
        cout << "Dequeue \n";
        if (IsEmpty())
        {
            cout << "Queue is Empty\n";
            return;
        }
        else if (front == rear)
        {
            rear = front = -1;
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
        }
    }

    int Front()
    {
        if (front == -1)
        {
            cout << "Cannot return front from empty queue\n";
            return -1;
        }
        return A[front];
    }

    void Print()
    {
        int count = (rear + MAX_SIZE - front) % MAX_SIZE + 1;
        cout << "Queue: ";
        for (int i = 0; i < count; i++)
        {
            int index = (front + i) % MAX_SIZE;
            cout << A[index] << " ";
        }
        cout << "\n";
    }
};

int main()
{
    Queue queue; 
    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Print();
    queue.Dequeue();
    queue.Print();
    queue.Enqueue(4);
    queue.Enqueue(5);
    queue.Print();
}