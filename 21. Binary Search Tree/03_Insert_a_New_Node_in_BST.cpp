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

TreeNode *insertNewNode(TreeNode *root, int newNode)
{
    if (root == nullptr)
    {
        return new TreeNode(newNode);
    }
    TreeNode *curr = root;
    while (true)
    {
        if (curr->val <= newNode)
        {
            if (curr->right != nullptr)
            {
                curr = curr->right;
            }
            else if (curr->right == nullptr)
            {
                curr->right = new TreeNode(newNode);
                break;
            }
        }
        else if (curr->val > newNode)
        {
            if (curr->left != nullptr)
            {
                curr = curr->left;
            }
            else if (curr->left == nullptr)
            {
                curr->left = new TreeNode(newNode);
                break;
            }
        }
    }

    return root;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}