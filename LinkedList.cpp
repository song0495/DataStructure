#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head;

void HeadInsert(int data)
{
    Node* temp = new Node;
    temp->data = data;

    // 头插的基本形式
    temp->next = head;
    head = temp;
}

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
    // 这里的head是第一个有数据的结点, 所以定位到前一个结点, 
    // 需要从head开始向后移动n-2次
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

void Delete(int n)
{
    Node* prev = head; // 删除结点的前一个结点
    if (n == 1)
    {
        head = prev->next;
    }
    else {
        for (int i = 0; i < n - 2; i++)
        {
            prev = prev->next;
        }
        Node* temp = prev->next; // 要删除的结点
        prev->next = temp->next;
        delete temp;
    }
    cout << "删除了第 " << n << " 位的数字" << endl;
}

int main()
{
    int num, data;
    head = nullptr;
    cout << "the num of data: " << endl;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cout << "enter the number" << endl;
        cin >> data;
        HeadInsert(data);
        Print();
    }

    Insert(4, 3);
    Print();

    Delete(3);
    Print();

    return 0;
}