/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Node
{
public:
    int value;
    Node *prev;
    Node *next;

    Node(int value)
    {
        this->value = value;
        prev = NULL;
        next = NULL;
    }

    ~Node()
    {
        int value = this->value;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory has been freed for node with value " << value << endl;
    }
};

// Printing the linked list
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Length of the linked list
int getLength(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    return len;
}

// Insert at Head
void insertAtHead(Node *&head, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
    }
    else
    {
        Node *temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

// Insert at Tail
void insertAtTail(Node *&tail, int data)
{
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(data);
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}

// Insert at any position

void insertAtPosition(Node *&head, Node *&tail, int position, int data)
{
    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }
    else
    {
        int count = 1;
        Node *temp = head;
        while (count < position - 1)
        {
            temp = temp->next;
            count++;
        }

        if (temp->next == NULL)
        {
            insertAtTail(tail, data);
            return;
        }

        Node *nodetoinsert = new Node(data);
        nodetoinsert->prev = temp;
        nodetoinsert->next = temp->next;
        temp->next->prev = nodetoinsert;
        temp->next = nodetoinsert;
    }
}

void deleteNodebyPosition(Node *&head, Node *&tail, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;

        int count = 1;

        while (count < position)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }

        if (curr->next == NULL) // Means if the position is the last position
        {
            tail = prev;
            prev->next = curr->next;
            curr->next = NULL;
            curr->prev = NULL;
            delete curr;
        }
        else
        {
            prev->next = curr->next;
            curr->next->prev = prev;
            curr->next = NULL;
            curr->prev = NULL;
            delete curr;
        }
    }
}

void deleteNodebyValue(Node *&head, Node *&tail, int value)
{
    Node *curr = head;
    Node *prev = NULL;

    int count = 1;

    while (curr->value != value)
    {
        prev = curr;
        curr = curr->next;
        count++;
    }

    if (count == 1) // Means if the value is at position 1
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
    }

    else if (curr->next == NULL) // Means if the value is in last position
    {
        tail = prev;
        prev->next = curr->next;
        curr->prev = NULL;
        delete curr;
    }

    else
    {
        prev->next = curr->next;
        curr->next->prev = prev;
        curr->prev = NULL;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    print(head);

    insertAtHead(head, 5);
    print(head);

    insertAtTail(tail, 20);
    print(head);

    insertAtPosition(head, tail, 3, 15);
    print(head);

    deleteNodebyValue(head, tail, 5);
    print(head);

    deleteNodebyPosition(head, tail, 2);
    print(head);

    return 0;
}