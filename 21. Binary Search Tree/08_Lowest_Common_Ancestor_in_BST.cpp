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

TreeNode *LowestCommonAncestor(TreeNode *root, TreeNode *u, TreeNode *v)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    int curr = root->val;
    if (curr < u->val and curr < v->val)
    {
        return LowestCommonAncestor(root->right, u, v);
    }
    else if (curr > u->val and curr > v->val)
    {
        return LowestCommonAncestor(root->left, u, v);
    }

    return root;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}