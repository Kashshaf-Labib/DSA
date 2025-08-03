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

int cnt = 0, ans;

void reverseInOrderTraversal(TreeNode *root, int k)
{
    if (root == nullptr or cnt >= k)
    {
        return;
    }

    reverseInOrderTraversal(root->right, k);

    cnt++;
    if (cnt == k)
    {
        ans = root->val;
        return;
    }

    reverseInOrderTraversal(root->left, k);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}
