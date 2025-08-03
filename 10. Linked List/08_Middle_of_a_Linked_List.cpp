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

int getLength(Node *head)
{
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }

    return len;
}

Node *findMiddle(Node *head)
{
    int len = getLength(head);
    int mid = (len / 2) + 1;
    Node *temp = head;
    int count = 1;
    while (count < mid)
    {
        temp = temp->next;
        count++;
    }

    return temp;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}