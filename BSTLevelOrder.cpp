#include <iostream>
#include <queue>
using namespace std;

struct BSTNode
{
    int data;
    BSTNode* left;
    BSTNode* right;
};

BSTNode* GetNewNode(int data)
{
    BSTNode* newNode = new BSTNode;
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

BSTNode* Insert(BSTNode* root, int data)
{
    if (root == nullptr)
        root = GetNewNode(data);
    else if (data <= root->data)
        root->left = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);
    return root;
}

void LevelOrder(BSTNode* root)
{
    if (root == nullptr)
        return;
    queue<BSTNode*> Queue;
    Queue.push(root);
    while (!Queue.empty())
    {
        BSTNode* temp = Queue.front();
        cout << temp->data << " ";
        if (temp->left != nullptr)
            Queue.push(temp->left);
        if (temp->right != nullptr)
            Queue.push(temp->right);
        Queue.pop();
    }
}

int main()
{
    BSTNode* root = nullptr;
    root = Insert(root, 10);
    root = Insert(root, 15);
    root = Insert(root, 20);
    root = Insert(root, 5);
    root = Insert(root, 7);
    root = Insert(root, 12);
    root = Insert(root, 18);
    cout << "levelorder: ";
    LevelOrder(root);
}