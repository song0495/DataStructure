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

BSTNode* FindMin(BSTNode* root)
{
    if (root == nullptr)
        return root;
    while (root->left != nullptr)
        root = root->left;
    return root;
}

BSTNode* GetSuccessor(BSTNode* root, int data)
{
    BSTNode* current = Find(root, data);
    if (current == nullptr)
        return current;
    if (current->right != nullptr) //有右子树, 后继节点就是右子树的最小结点
        return FindMin(current->right);
    else // 没有右子树, 则寻找该结点右边的最深祖先, 该结点处于祖先的左子树中
    {
        BSTNode* successor = nullptr;
        BSTNode* ancestor = root;
        while (ancestor != current)
        /*
        这里的核心思想是, 通过完成ancestor到current的遍历, 寻找出successor
        当current的值小于ancestor的值时, 说明current位于ancestor的左子树中, 
        但是无法保证深度是最深的, 所以需要继续向左寻找新的ancestor
        当current的值大于ancestor的值时, 说明current位于ancestor的右子树中,
        说明当前的ancestor就是满足条件的ancestor, 即successor, 后续的循环
        只是为了完成到current的遍历, 退出循环
        */
        {
            if (current->data < ancestor->data)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
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

    BSTNode* successor = GetSuccessor(root, 10);
    if (successor == nullptr)
        cout << "No successor Found" << endl;
    else
        cout << "Successor is " << successor->data << endl;
}