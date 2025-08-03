/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }

    ~Node()
    {
        int data = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory freed for node with value " << data << endl;
    }
};

void print(Node *&head, Node *&tail)
{
    Node *temp = head;
    while (temp->next != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(data);
        temp->next = head;
        tail->next = temp;
        head = temp;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        tail = temp;
        head = temp;
    }
    else
    {
        Node *temp = new Node(data);
        tail->next = temp;
        temp->next = head;
        tail = temp;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    if (position == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }
    int count = 1;
    Node *temp = head;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == head) // Means inserting at the last position
    {
        insertAtTail(head, tail, data);
        return;
    }

    Node *nodetoinsert = new Node(data);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}

void insertAfterNode(Node *&head, Node *&tail, int key, int v)
{
    Node *temp = head;
    bool found = false;

    while (1)
    {
        temp = temp->next;
        if (temp->data == v)
        {
            found = true;
            break;
        }
        if (temp->next == head)
        {
            break;
        }
    }

    if (found)
    {
        if (temp->next == head) // Means if the temp is the tail
        {
            Node *nodeToInsert = new Node(key);
            temp->next = nodeToInsert;
            nodeToInsert->next = head;
            tail=nodeToInsert;
            return;
        }

        Node *nodeToInsert = new Node(key);
        nodeToInsert->next = temp->next;
        temp->next = nodeToInsert;
    }
    else
    {
        cout << "Value not found" << endl;
    }
}

void updateNode(Node *&head, Node *&tail, int value, int key)
{
    bool found = false;
    Node *temp = head;
    while (temp->data != value)
    {
        temp = temp->next;
        if (temp->data == value)
        {
            found = true;
        }
        if (temp->next == head)
        {
            break;
        }
    }
    if (!found)
    {
        cout << "Value not found" << endl;
        return;
    }
    temp->data = key;
}

void deleteNodebyPosition(Node *&head, Node *&tail, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        tail->next = head;
        temp->next = NULL;
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
        if (curr->next == head)
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

void deletNodebyValue(Node *&head, Node *&tail, int value)
{
    int count = 1;
    Node *prev = NULL;
    Node *curr = head;
    while (curr->data != value)
    {
        prev = curr;
        curr = curr->next;
        count++;
    }
    if (count == 1)
    {
        Node *temp = head;
        head = head->next;
        tail->next = head;
        temp->next = NULL;
        delete temp;
    }
    else if (curr->next == head)
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

    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    insertAtHead(head, tail, 5);
    insertAtHead(head, tail, 2);
    insertAtTail(head, tail, 15);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 25);
    insertAtPosition(head, tail, 12, 4);
    deleteNodebyPosition(head, tail, 7);
    deletNodebyValue(head, tail, 5);

    print(head, tail);
    cout << head->data << " " << tail->data << endl;

    return 0;
}