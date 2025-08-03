/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> nodeValues;
int ans, cnt = 0;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

// Naive approach. Complexity O(NlogN)
void preOrderTraversal(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    nodeValues.push_back(root->val);

    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Efficient Approach

void inOrderTraversal(TreeNode *root, int k)
{
    if (root == nullptr or cnt >= k)
    {
        return;
    }

    inOrderTraversal(root->left, k);

    if (cnt == k)
    {
        ans = root->val;
        return;
    }

    cnt++;
    inOrderTraversal(root->right, k);
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    TreeNode *root = nullptr;
    // Naive approach:
    preOrderTraversal(root);
    sort(nodeValues.begin(), nodeValues.end());

    // Efficient approach:
    inOrderTraversal(root, 5);

    return 0;
}