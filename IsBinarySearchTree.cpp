#include <iostream>
using namespace std;

#define MIN -100
#define MAX 100

struct BSTNode
{
    int data;
    BSTNode* left;
    BSTNode* right;
};

bool IsSubtreeLesser(BSTNode* root, int value) // 判断子树上的结点是否都比根结点小
{
    if (root == nullptr)
        return true;
    if (root->data <= value && IsSubtreeLesser(root->left, root->data) &&
        IsSubtreeLesser(root->right, root->data))
    // 1. 子树根结点数据小于根节点数据 2. 判断子树的左右子树是否满足条件
        return true;
    else
        return false;
}

bool IsSubtreeGreater(BSTNode* root, int value) // 判断子树上的结点是否都比根结点大
{
    if (root == nullptr)
        return true;
    if (root->data > value && IsSubtreeGreater(root->left, root->data)
        && IsSubtreeGreater(root->right, root->data))
    // 1. 子树根结点数据大于根节点数据 2. 判断子树的左右子树是否满足条件
        return true;
    else
        return false;
}

bool IsBinarySearchTree1(BSTNode* root)
{
    if (root == nullptr)
        return true;
    if (IsSubtreeLesser(root->left, root->data) && IsSubtreeGreater(root->right, root->data) &&
        IsBinarySearchTree1(root->left) && IsBinarySearchTree1(root->right))
        // 1. 判断左右子树是否为二叉搜索树 2. 判断根节点和左右子树结点数据大小
        return true;
    else
        return false;
}

bool IsBSTUtil(BSTNode* root, int min, int max)
{
    if (root == nullptr)
        return true;
    if (root->data > min && root->data < max && IsBSTUtil(root->left, min, root->data) &&
        IsBSTUtil(root->right, root->data, max))
    // 对判断根节点和左右子树结点数据大小做出改进, 给每个结点一个数据范围, 减少遍历, 降低时间复杂度
        return true;
    else
        return false;
}

bool IsBinarySearchTree2(BSTNode* root)
{
    return IsBSTUtil(root, MIN, MAX);
}

bool IsBinarySearchTree3(BSTNode* root, int value)
// 利用中序排序, 判断当前节点数据是否小于前一结点数据
// 中序排序后的数据递增
{
    if(root == nullptr)
        return true;
    IsBinarySearchTree3(root->left, root->data);
    if (root->data > value)
        return false;
    IsBinarySearchTree3(root->right, root->data);

    return true;
}
