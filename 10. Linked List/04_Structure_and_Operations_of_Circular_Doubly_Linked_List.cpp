/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
    }

    ~Node()
    {
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

void print(Node *&head)
{
    Node *temp = head;

    while (temp->next != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

void printFromTailtoHead(Node *&head, Node *&tail)
{
    Node *temp = tail;
    while (temp != head)
    {
        cout << temp->data << " ";
        temp = temp->prev;
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
        temp->prev = tail;
        head->prev = temp;
        tail->next = temp;
        head = temp;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    temp->prev = tail;
    tail->next = temp;
    head->prev = temp;
    tail = temp;
}

void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    if (position == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }
    Node *temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == head)
    {
        insertAtTail(head, tail, data);
        return;
    }

    Node *nodetoinsert = new Node(data);
    nodetoinsert->prev = temp;
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
    temp->next->prev = nodetoinsert;
}

void updateNode(Node *&head, Node *&tail, int value, int key)
{
    Node *temp = head;
    bool found = false;
    while (temp->data != value)
    {
        temp = temp->next;
        if (temp->data == value)
        {
            found = true;
            break;
        }
        if (temp->next == head)
        {
            break;
        }
    }
    if (!found)
    {
        cout << "Value not found" << endl;
    }
    else
    {
        temp->data = key;
        cout << "Value updated";
    }
}

void deleteNodebyPosition(Node *&head, Node *&tail, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        tail->next = head;
        head->prev = tail;
        temp->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *prev = NULL;
        Node *curr = head;
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
            prev->next = head;
            head->prev = prev;
            curr->prev = NULL;
            curr->next = NULL;
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
}

void deleteTail(Node *&head, Node *&tail)
{
    if (tail == nullptr)
    {
        cout << "List is empty. Cannot delete tail." << endl;
        return;
    }

    Node *temp = tail;

    if (temp->prev != nullptr)
    {
        tail = temp->prev;
        tail->next = head;
        head->prev = tail;
        temp->prev = nullptr;
        temp->next = nullptr;
        delete temp;
    }
    else
    {
        // If there is only one node in the list
        delete temp;
        head = tail = nullptr;
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
    insertAtPosition(head, tail, 12, 4);
    deleteNodebyPosition(head, tail, 6);
    print(head);
    // printFromTailtoHead(head, tail);
    cout << head->data << " " << tail->data << endl;

    return 0;
}
