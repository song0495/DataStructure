#include <iostream>
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

bool Search(BSTNode* root, int data)
{
    if (root == nullptr)
        return false;
    else if (root->data == data)
        return true;
    else if (data <= root->data)
        return Search(root->left, data);
    else 
        return Search(root->right, data);
}

int FindMinRecursion(BSTNode* root)
{
    if (root == nullptr)
    {
        cout << "empty tree" << endl;
        return -1;
    }
    else if (root->left == nullptr)
        return root->data;
    
    return FindMinRecursion(root->left);  
}

int FindMaxRecursion(BSTNode* root)
{
    if (root == nullptr)
    {
        cout << "empty tree" << endl;
        return -1;
    }
    else if (root->right == nullptr)
        return root->data;
    
    return FindMaxRecursion(root->right);  
}

int FindMinLoop(BSTNode* root)
{
    if (root == nullptr)
    {
        cout << "empty tree" << endl;
        return -1;
    }
    while (root->left != nullptr)
        root = root->left;
    
    return root->data;
}

int FindMaxLoop(BSTNode* root)
{
    if (root == nullptr)
    {
        cout << "empty tree" << endl;
        return -1;
    }
    while (root->right != nullptr)
        root = root->right;
    
    return root->data;
}

int FindHeight(BSTNode* root)
{
    if (root == nullptr)
        return -1;
    return max(FindHeight(root->left), FindHeight(root->right)) + 1;
}

int main()
{
    int num;
    BSTNode* root = nullptr;
    root = Insert(root, 10);
    root = Insert(root, 15);
    root = Insert(root, 20);
    root = Insert(root, 5);
    root = Insert(root, 7);
    root = Insert(root, 12);
    root = Insert(root, 18);

    /*
    cout << "search num: " << endl;
    cin >> num;
    if (Search(root, num))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;
    */
    
    cout << "loop result: " << FindMinLoop(root) << " recursion result: " << FindMinRecursion(root) << endl;
    cout << "loop result: " << FindMaxLoop(root) << " recursion result: " << FindMaxRecursion(root) << endl;

    cout << "height: " << FindHeight(root) << endl;
}
