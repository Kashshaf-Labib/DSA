/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Deque
{
    int *arr;
    int size;
    int qfront;
    int rear;

public:
    Deque(int size)
    {
        this->size = size;
        arr = new int[size];
        qfront = -1;
        rear = -1;
    }

    void push_front(int value)
    {
        // in case array is full
        if ((qfront == 0 and rear == size - 1) || (rear == (qfront - 1) % (size - 1)))
        {
            cout << "Queue is full" << endl;
        }
        else if (qfront == -1) // first element to push
        {
            qfront = 0;
            rear = 0;
            arr[qfront] = value;
        }
        else if (qfront == 0 and rear < size - 1) // circular condition
        {
            qfront = size - 1;
            arr[qfront] = value;
        }
        else // normal push
        {
            qfront--;
            arr[qfront] = value;
        }
    }

    void push_back(int value) // same as circular queue
    {
        if ((qfront == 0 and rear == size - 1) || (rear == (qfront - 1) % (size - 1)))
        {
            cout << "Queue is full" << endl;
        }
        else if (qfront == -1)
        {
            qfront = rear = 0;
            arr[rear] = value;
        }
        else if (rear == size - 1 and qfront != 0)
        {
            rear = 0;
            arr[rear] = value;
        }
        else
        {
            rear++;
            arr[rear] = value;
        }
    }

    int pop_front() // same as circular queue
    {
        if (qfront == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int ans = -1;
        if (qfront == rear)
        {
            ans = arr[qfront];
            arr[qfront] = -1;
            qfront = -1;
            rear = -1;
        }
        else if (qfront == size - 1)
        {
            ans = arr[qfront];
            arr[qfront] = -1;
            qfront = 0;
        }
        else
        {
            ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
        }

        return ans;
    }

    int pop_back()
    {
        if (qfront == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int ans = -1;
        if (qfront == rear)
        {
            ans = arr[rear];
            arr[rear] = -1;
            qfront = -1;
            rear = -1;
        }
        else if (rear == 0)
        {
            ans = arr[rear];
            arr[rear] = -1;
            rear = size - 1;
        }
        else
        {
            ans = arr[rear];
            arr[rear] = -1;
            rear--;
        }
        return ans;
    }

    int front()
    {
        if (qfront == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[qfront];
    }

    int back()
    {
        if (qfront == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[rear];
    }
};
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    Deque dq(3);
    dq.push_front(1);
    dq.push_back(2);
    dq.pop_front();
    dq.push_front(3);

    cout << dq.front() << " " << dq.back() << endl;

    return 0;
}