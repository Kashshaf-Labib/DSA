/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *parent;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : data(0), left(nullptr), right(nullptr), parent(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr), parent(nullptr) {}
};

TreeNode *insert(TreeNode *root, int data, int parentData, int isLeft)
{
    if (root == nullptr)
    {
        if (parentData == 0)
        {
            root = new TreeNode(data);
            root->parent = nullptr;
        }
        return root;
    }

    if (root->data == parentData)
    {
        if (isLeft == 1)
        {
            root->left = new TreeNode(data);
            root->left->parent = root;
        }
        else
        {
            root->right = new TreeNode(data);
            root->right->parent = root;
        }
    }
    else
    {
        root = insert(root->left, data, parentData, isLeft);
        root = insert(root->right, data, parentData, isLeft);
    }

    return root;
}

int findCeil(TreeNode *root, int key)
{
    int ceil = -1;
    while (root != nullptr)
    {
        if (root->data == key)
        {
            ceil = root->data;
            return ceil;
        }

        if (root->data < key)
        {
            root = root->right;
        }
        else
        {
            ceil = root->data;
            root = root->left;
        }
    }

    return ceil;
}

int findFloor(TreeNode *root, int key)
{
    int floor = -1;
    while (root != nullptr)
    {
        if (root->data == key)
        {
            floor = root->data;
            return floor;
        }
        if (root->data > key)
        {
            root = root->left;
        }
        else
        {
            floor = root->data;
            root = root->right;
        }
    }
    return floor;
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}