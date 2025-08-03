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

void search(TreeNode *node, int key)
{
    if (node == nullptr)
    {
        return;
    }

    bool found = false;

    queue<TreeNode *> q;
    q.push(node);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        if (node->data == key)
        {
            found = true;
            cout << "Present, ";

            if (node->left != nullptr)
            {
                cout << "Left"
                     << "(" << node->left->data << ") ";
            }
            else
            {
                cout << "Left(N)";
            }
            cout << ", ";
            if (node->right != nullptr)
            {
                cout << "Right"
                     << "(" << node->right->data << ") ";
            }
            else
            {
                cout << "Right(N)";
            }

            break;
        }

        q.pop();
        if (node->left)
        {
            q.push(node->left);
        }
        if (node->right)
        {
            q.push(node->right);
        }
    }

    if (!found)
    {
        cout << "Not Present" << endl;
    }
}

void remove(TreeNode *node, int key)
{
    if (node == nullptr)
    {
        return;
    }

    queue<TreeNode *> q;
    bool found = false;
    q.push(node);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        if (node->left != nullptr)
        {
            if (node->left->data == key)
            {
                found = true;
                node->left = nullptr;
                break;
            }
        }
        if (node->right != nullptr)
        {
            if (node->right->data == key)
            {
                found = true;
                node->right = nullptr;
                break;
            }
        }
        q.pop();
        if (node->left)
        {
            q.push(node->left);
        }
        if (node->right)
        {
            q.push(node->right);
        }
    }

    if (!found)
    {
        cout << "Not present" << endl;
    }
}

int height(TreeNode *node)
{

    if (node == nullptr)
    {
        return -1;
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    return 1 + max(leftHeight, rightHeight);
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

    preOrderTraversal(root);
    cout << endl;

    while (true)
    {
        int op;
        cin >> op;
        if (op == 2)
        {
            int toDelete;
            cin >> toDelete;
            remove(root, toDelete);
            preOrderTraversal(root);
            cout << endl;
        }
        else if (op == 3)
        {
            int toFind;
            cin >> toFind;
            search(root, toFind);
            cout << endl;
        }
        else if (op == 4)
        {
            cout << height(root) << endl;
        }
    }

    return 0;
}