/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Stack
{
    Node *top; // Head
    int sz;

public:
    Stack()
    {
        top = NULL;
        sz = 0;
    }

    void push(int value)
    {
        Node *temp = new Node();
        temp->data = value;
        temp->next = top;
        top = temp;
        sz++;
    }

    void pop()
    {
        if (top != NULL)
        {
            Node *temp = top;
            top = top->next;
            temp->next = NULL;
            delete temp;
            sz--;
        }
        else
        {
            cout << "Stack underflow" << endl;
        }
    }

    bool empty()
    {
        if (top == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int peek()
    {
        if (top != NULL)
        {
            return top->data;
        }
        else
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    int size()
    {
        return sz;
    }
};
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    Stack st;
    st.push(10);
    st.push(15);
    st.push(20);

    st.peek();

    return 0;
}
