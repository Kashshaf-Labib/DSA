/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct TreeNode
{
    char data;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode() : data('0'), left(nullptr), right(nullptr), parent(nullptr) {}
    TreeNode(char x) : data(x), left(nullptr), right(nullptr), parent(nullptr) {}
};

TreeNode *insert(TreeNode *root, char data, char parentData, int isLeft)
{
    if (root == nullptr)
    {
        if (parentData == '0')
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
        return;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *current = q.front();
        q.pop();

        cout << current->data;

        if (current->parent != nullptr)
        {
            cout << "(" << current->parent->data << ") ";
        }
        else
        {
            cout << "(N) ";
        }

        if (current->left != nullptr)
            q.push(current->left);

        if (current->right != nullptr)
            q.push(current->right);
    }
}

void preOrderTraversal(TreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }

    cout << node->data;
    if (node->parent != nullptr)
    {
        cout << "(" << node->parent->data << ")";
    }
    else
    {
        cout << "(N)";
    }
    cout << " ";
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

void inOrderTraversal(TreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }

    inOrderTraversal(node->left);

    cout << node->data;
    if (node->parent != nullptr)
    {
        cout << "(" << node->parent->data << ")";
    }
    else
    {
        cout << "(N)";
    }
    cout << " ";

    inOrderTraversal(node->right);
}

void postOrderTraversal(TreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }

    postOrderTraversal(node->left);
    postOrderTraversal(node->right);

    cout << node->data;
    if (node->parent != nullptr)
    {
        cout << "(" << node->parent->data << ")";
    }
    else
    {
        cout << "(N)";
    }
    cout << " ";
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
        char data, parentData;
        int child;
        cin >> data >> parentData >> child;
        root = insert(root, data, parentData, child);
    }

    cout << "PreOrder Traversal: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "PostOrder Traversal: ";
    postOrderTraversal(root);
    cout << endl;

    cout << "InOrder Traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "LevelOrder Traversal: ";
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}