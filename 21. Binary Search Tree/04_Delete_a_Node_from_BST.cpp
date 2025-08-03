/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->val == key)
    {
        return helper(root);
    }

    TreeNode *dummy = root;

    while (root != nullptr)
    {
        if (root->val > key)
        {
            if (root->left != nullptr and root->left->val == key)
            {
                root->left = helper(root->left);
                break;
            }
            else
            {
                root = root->left;
            }
        }
        else
        {
            if (root->right != nullptr and root->right->val == key)
            {
                root->right = helper(root->right);
                break;
            }
            else
            {
                root = root->right;
            }
        }
    }
    return dummy;
}

TreeNode *helper(TreeNode *root)
{
    if (root->left == nullptr)
    {
        return root->right;
    }
    if (root->right == nullptr)
    {
        return root->left;
    }

    TreeNode *rightSubtree = root->right;
    TreeNode *rightMostNode = findFarthestRight(root->left);

    rightMostNode->right = rightSubtree;

    return root->left;
}

TreeNode *findFarthestRight(TreeNode *root)
{
    if (root->right == nullptr)
    {
        return root;
    }
    return findFarthestRight(root->right);
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}