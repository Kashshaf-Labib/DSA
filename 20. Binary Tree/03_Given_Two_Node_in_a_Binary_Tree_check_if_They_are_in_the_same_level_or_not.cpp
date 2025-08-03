/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

map<int, int> levelofNode;
int level = 0;

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
        int levelSize = q.size();
        while (levelSize--)
        {
            TreeNode *current = q.front();
            q.pop();

            levelofNode[current->data] = level;

            if (current->left)
            {
                q.push(current->left);
            }
            if (current->right)
            {
                q.push(current->right);
            }
        }
        level++;
    }
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
        int data, parentData, isLeft;
        cin >> data >> parentData >> isLeft;
        root = insert(root, data, parentData, isLeft);
    }

    levelOrderTraversal(root);

    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        if (levelofNode[u] == levelofNode[v])
        {
            cout << "Yes (Level " << levelofNode[u] << ")" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}