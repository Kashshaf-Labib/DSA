/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

void reverse(Node *&head, Node *curr, Node *prev)
{
    if (curr == NULL)
    {
        head = prev;
        return;
    }
    Node *forward = curr->next;
    curr->next = prev;
    reverse(head, forward, curr);
}

Node *reverseLinkedList(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *forward = NULL;

    reverse(head, curr, prev);

    return head;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}