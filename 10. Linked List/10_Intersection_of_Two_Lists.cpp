#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

Node *findIntersection(Node *list1, Node *list2)
{
    Node *result = nullptr;
    Node *tail = nullptr;

    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->data == list2->data)
        {
            if (result == nullptr)
            {
                result = new Node(list1->data);
                tail = result;
            }
            else
            {
                tail->next = new Node(list1->data);
                tail = tail->next;
            }
            list1 = list1->next;
            list2 = list2->next;
        }
        else if (list1->data < list2->data)
        {
            list1 = list1->next;
        }
        else
        {
            list2 = list2->next;
        }
    }

    return result;
}

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *list1 = nullptr;
    Node *list2 = nullptr;

    // Input for the first list
    int num;
    cout << "Enter the first list (sorted, terminate with -1): ";
    while (true)
    {
        cin >> num;
        if (num == -1)
        {
            break;
        }
        if (list1 == nullptr)
        {
            list1 = new Node(num);
        }
        else
        {
            Node *temp = new Node(num);
            temp->next = list1;
            list1 = temp;
        }
    }

    // Input for the second list
    cout << "Enter the second list (sorted, terminate with -1): ";
    while (true)
    {
        cin >> num;
        if (num == -1)
        {
            break;
        }
        if (list2 == nullptr)
        {
            list2 = new Node(num);
        }
        else
        {
            Node *temp = new Node(num);
            temp->next = list2;
            list2 = temp;
        }
    }

    // Find and print the intersection
    Node *intersection = findIntersection(list1, list2);

    cout << "Intersection: ";
    if (intersection != nullptr)
    {
        printList(intersection);
    }
    else
    {
        cout << "empty" << endl;
    }

    // Clean up memory
    while (list1 != nullptr)
    {
        Node *temp = list1;
        list1 = list1->next;
        delete temp;
    }

    while (list2 != nullptr)
    {
        Node *temp = list2;
        list2 = list2->next;
        delete temp;
    }

    while (intersection != nullptr)
    {
        Node *temp = intersection;
        intersection = intersection->next;
        delete temp;
    }

    return 0;
}
