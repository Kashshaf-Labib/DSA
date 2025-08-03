/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
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
        root->left = insert(root->left, data, parentData, isLeft);
        root->right = insert(root->right, data, parentData, isLeft);
    }

    return root;
}

bool isSymmetricHelp(TreeNode *left, TreeNode *right)
{
    if (left == nullptr or right == nullptr)
    {
        return left == right;
    }

    if (left->data != right->data)
    {
        return false;
    }

    return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
}

bool isSymmetric(TreeNode *root)
{

    return root == nullptr or isSymmetricHelp(root->left, root->right);
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    TreeNode *root = nullptr;

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int data, parentData, child;
        cin >> data >> parentData >> child;
        root = insert(root, data, parentData, child);
    }

    if (isSymmetric(root))
    {
        cout << "Yes" << endl;
    }

    return 0;
}