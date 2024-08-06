#include <iostream>
using namespace std;

struct BSTNode
{
    int data;
    BSTNode* left;
    BSTNode* right;
};

BSTNode* FindMin(BSTNode* root)
{
    if (root == nullptr)
    {
        cout << "empty tree" << endl;
        return root;
    }
    else if (root->left == nullptr)
        return root;
    
    return FindMin(root->left);  
}

BSTNode* Delete(BSTNode* root, int value)
{
    if (root == nullptr)
        return root;
    else if (root->data < value)
        root->right = Delete(root->right, value);
    else if (root->data > value)
        root->left = Delete(root->left, value); // 到这一步, 找到需要删除的结点
    else
    {
        if (root->left == nullptr && root->right == nullptr) // 被删除结点是叶节点
        {
            delete root;
            root = nullptr;
        }
        else if (root->left == nullptr) // 被删除结点无左孩
        {
            BSTNode* temp = root;
            root = root->right; // 直接替换
            delete temp;
        }
        else if (root->right == nullptr) // 被删除结点无右孩
        {
            BSTNode* temp = root;
            root = root->left; // 直接替换
            delete temp;
        }
        else // 被删除结点左右皆有
        {
            BSTNode* temp = FindMin(root->right); // 寻找最小的结点
            root->data = temp->data; // 修改当前结点的值
            root->right = Delete(root->right, temp->data); // 在右子树中删除最小结点
        }
        /*
        else // 被删除结点左右皆有
        {
            BSTNode* temp = FindMax(root->left); // 左子树的最大结点
            root->data = temp->data;
            root->left = Delete(root->left, temp->data);
        }
        */
    }

    return root;
}