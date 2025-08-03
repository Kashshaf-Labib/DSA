/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node
{
    Node *next[26 + 1];
    bool endmark = false;

    Node()
    {
        endmark = false;
        for (int i = 0; i < 26; i++)
        {
            next[i] = NULL;
        }
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node;
    }

    void insert(string str)
    {
        Node *curr = root;
        for (int i = 0; i < str.length(); i++)
        {
            int id = str[i] - 'a';
            if (curr->next[id] == NULL)
            {
                curr->next[id] = new Node();
            }
            curr = curr->next[id];
        }

        curr->endmark = true;
    }

    bool search(string str)
    {
        Node *curr = root;
        for (int i = 0; i < str.length(); i++)
        {
            int id = str[i] - 'a';
            if (curr->next[id] == NULL)
            {
                return false;
            }
            curr = curr->next[id];
        }

        return curr->endmark;
    }

    bool prefixSearch(string str)
    {
        Node *curr = root;
        for (int i = 0; i < str.length(); i++)
        {
            int id = str[i] - 'a';
            if (curr->next[id] == NULL)
            {
                return false;
            }
        }
        return true;
    }

    void del(Node *curr) // after each test case clear up the memory of a trie
    {
        for (int i = 0; i < 26; i++)
        {
            if (curr->next[i] != NULL)
            {
                del(curr->next[i]);
            }
        }
        delete (curr);
    }

    Node *deleteWord(Node *root, string str, int i)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (i == str.length())
        {
            root->endmark = false;

            if (!hasChildren(root))
            {
                delete (root);
                root == NULL;
            }
            return root;
        }

        int index = str[i] - 'a';

        root->next[index] = deleteWord(root->next[index], str, i + 1);

        if (!hasChildren(root) and root->endmark == false)
        {
            delete (root);
            root = NULL;
        }
        return root;
    }

    bool hasChildren(Node *current)
    {
        for (int i = 0; i < 26; i++)
        {
            if (current->next[i] != NULL)
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}