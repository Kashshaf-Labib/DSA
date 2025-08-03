/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Stack
{
public:
    int *arr;
    int top;
    int size;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int value)
    {
        if (top < size - 1)
        {
            top++;
            arr[top] = value;
        }
        else
        {
            cout << "Stack overflow" << endl;
        }
    }
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack underflow" << endl;
        }
    }

    int peek()
    {
        if (top > -1 and top < size)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }
    bool empty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }
};


int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    Stack st(5);

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    st.pop();
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek();

    return 0;
}