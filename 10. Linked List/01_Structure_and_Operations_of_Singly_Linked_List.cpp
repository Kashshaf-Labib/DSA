/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory has been freed for node with value " << value << endl;
    }
};

void insertAtHead(Node *&head, int data) // Head is Node type pointer
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node *&head, Node *&tail, int position, int data)
{
    // if position is 1st
    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }
    int count = 1;
    Node *temp = head;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL) // if the position is the last position
    {
        insertAtTail(tail, data);
        return;
    }

    Node *nodetoinsert = new Node(data);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}

void print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteNodebyPosition(Node *&head, Node *&tail, int position)
{
    // Deleting first node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    // Deleting node at any other position
    else
    {
        int count = 1;
        Node *curr = head;
        Node *prev = NULL;
        while (count < position)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        if (curr->next == NULL) // Means if the position is at the end (we need to handle the tail)
        {
            tail = prev;
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }
        else
        {
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }
    }
}

void deleteNodebyValue(Node *&head, Node *&tail, int value)
{
    Node *prev = NULL;
    Node *curr = head;
    int count = 1;
    while (curr->data != value)
    {
        prev = curr;
        curr = curr->next;
        count++;
    }
    if (count == 1) // Means the value is at position 1
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else if (curr->next == NULL) // Means if the value is at the last position (we need to handle the tail manually)
    {
        tail = prev;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
    else
    {
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    // Creating a node
    Node *node1 = new Node(10);
    // cout << node1->data << " " << node1->next << endl;
    print(node1);

    // Head and tail both pointing to node1
    Node *head = node1;
    Node *tail = node1;

    // Inserting head to the list
    insertAtHead(head, 12);
    insertAtHead(head, 15);
    print(head);

    // insert at tail
    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    print(head);

    // insert at nth position
    insertAtPosition(head, tail, 3, 25);
    print(head);

    // deleting at position 6
    deleteNodebyPosition(head, tail, 6);
    print(head);

    // deleting value 12
    deleteNodebyValue(head, tail, 12);
    print(head);

    return 0;
}