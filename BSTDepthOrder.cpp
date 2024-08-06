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

void PreOrder(BSTNode* root)
{
    if(root == nullptr)
        return;
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(BSTNode* root)
{
    if(root == nullptr)
        return;
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

void PostOrder(BSTNode* root)
{
    if(root == nullptr)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
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

    cout << "preorder: ";
    PreOrder(root);
    cout << endl;

    cout << "inorder: ";
    InOrder(root);
    cout << endl;

    cout << "postorder: ";
    PostOrder(root);
    cout << endl;
}