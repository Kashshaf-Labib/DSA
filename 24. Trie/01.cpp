/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node
{
    Node *links[26];
    bool flag = false;

    // checks if the reference trie is present or not:
    // if ch is present then reference of ch will not be NULL
    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    // creating reference Trie for character ch
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    // to get the next node for traversal
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    // setting the flag to true if it is the end of the word:
    void setEnd()
    {
        flag = true;
    }

    // checking if the word is completed or not
    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        // Initializing dummy node pointing to root initially:
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }

        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (!node->containsKey(prefix[i]))
            {
                return false;
            }
            node = node->get(prefix[i]);
        }

        // If we passed all the prefixes we do not to check if the current node is holding true or false
        return true;
    }
};
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}