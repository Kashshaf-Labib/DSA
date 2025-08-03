/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool checkRange(TreeNode *root, int minVal, int maxVal)
{
    if (root == nullptr)
    {
        return true;
    }

    if (root->val >= maxVal or root->val <= minVal)
    {
        return false;
    }

    return checkRange(root->left, minVal, root->val) and checkRange(root->right, root->val, maxVal);
}

// checking with inOrder Traversal:

bool isValidCheck(TreeNode *root, int &prev)
{
    if (root == nullptr)
    {
        return true;
    }

    if (!isValidCheck(root->left, prev))
    {
        return false;
    }

    if (root->val <= prev)
    {
        return false;
    }
    prev = root->val;

    return isValidCheck(root->right, prev);
}

bool isValidBST(TreeNode *root)
{
    int prev = INT_MIN;
    return isValidCheck(root, prev);
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}