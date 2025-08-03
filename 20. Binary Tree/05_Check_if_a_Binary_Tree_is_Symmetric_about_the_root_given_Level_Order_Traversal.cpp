/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

TreeNode *constructTree(vector<int> &levelOrder)
{
    if (levelOrder.empty())
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(levelOrder[0]);

    queue<TreeNode *> q;
    q.push(root);

    int i = 1;

    while (i < levelOrder.size())
    {
        TreeNode *current = q.front();
        q.pop();

        if (i < levelOrder.size() and levelOrder[i] != -1)
        {
            current->left = new TreeNode(levelOrder[i]);
            q.push(current->left);
        }
        i++;
        if (i < levelOrder.size() and levelOrder[i] != -1)
        {
            current->right = new TreeNode(levelOrder[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

void levelOrderTraversal(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *current = q.front();
        q.pop();
        cout << current->data << " ";

        if (current->left)
        {
            q.push(current->left);
        }
        if (current->right)
        {
            q.push(current->right);
        }
    }
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
    if (root == nullptr)
    {
        return true;
    }

    return isSymmetricHelp(root->left, root->right);
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> levelOrder;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        levelOrder.push_back(x);
    }

    TreeNode *root = constructTree(levelOrder);

    if (isSymmetric(root))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}