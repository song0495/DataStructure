#include <iostream>
using namespace std;

struct BSTNode
{
    int data;
    BSTNode* left;
    BSTNode* right;
};

BSTNode* Find(BSTNode* root, int data)
{
    if (root == nullptr)
        return root;
    else if (root->data == data)
        return root;
    else if (root->data < data) 
        return Find(root->right, data);
    else 
        return Find(root->left, data);
}

BSTNode* FindMax(BSTNode* root)
{
    if (root == nullptr)
        return root;
    while (root->right != nullptr)
        root = root->right;
    return root;
}

BSTNode* GetPredecessor(BSTNode* root, int data) // 整体想法与successor类似
{
    BSTNode* current = Find(root, data);
    if (current == nullptr)
        return current;
    if (current->left != nullptr) //有左子树, 前任节点就是左子树的最大结点
        return FindMax(current->left);
    else // 没有左子树, 则寻找该结点左边的最深祖先, 该结点处于祖先的右子树中
    {
        BSTNode* successor = nullptr;
        BSTNode* ancestor = root;
        while (ancestor != current)
        {
            if (current->data > ancestor->data)
            {
                successor = ancestor;
                ancestor = ancestor->right;
            }
            else
                ancestor = ancestor->left;
        }
        return successor;
    }
}

void InOrder(BSTNode* root)
{
    if(root == nullptr)
        return;
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

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

int main()
{
    BSTNode* root = nullptr;
    root = Insert(root, 3); 
    root = Insert(root, 5);
    root = Insert(root, 10); 
    root = Insert(root, 11);
    root = Insert(root, 19); 
    root = Insert(root, 8);

    InOrder(root);
    cout << endl;

    BSTNode* Predecessor = GetPredecessor(root, 19);
    if (Predecessor == nullptr)
        cout << "No predecessor Found" << endl;
    else
        cout << "predecessor is " << Predecessor->data << endl;
}