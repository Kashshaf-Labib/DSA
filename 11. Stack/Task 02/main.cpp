/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Dequeue
{
    int *arr;
    int size;
    int qfront;
    int rear;

public:
    Dequeue(int size)
    {
        this->size = size;
        arr = new int[size];
        qfront = -1;
        rear = -1;
    }

    int pushLeft(int value)
    {
        int ans = -101;
        // in case array is full
        if ((qfront == 0 and rear == size - 1) || (rear == (qfront - 1) % (size - 1)))
        {
            ans = -101;
        }
        else if (qfront == -1) // first element to push
        {
            qfront = 0;
            rear = 0;
            arr[qfront] = value;
            ans = value;
        }
        else if (qfront == 0) // circular condition
        {
            qfront = size - 1;
            arr[qfront] = value;
            ans = value;
        }
        else // normal push
        {
            qfront--;
            arr[qfront] = value;
            ans = value;
        }
        return ans;
    }

    int pushRight(int value) // same as circular queue
    {
        int ans = -101;
        if ((qfront == 0 and rear == size - 1) || (rear == (qfront - 1) % (size - 1)))
        {
            ans = -101;
        }
        else if (qfront == -1)
        {
            qfront = rear = 0;
            arr[rear] = value;
            ans = value;
        }
        else if (rear == size - 1)
        {
            rear = 0;
            arr[rear] = value;
            ans = value;
        }
        else
        {
            rear++;
            arr[rear] = value;
            ans = value;
        }
        return ans;
    }

    int popLeft() // same as circular queue
    {
        if (qfront == -1)
        {
            return -101;
        }
        int ans = -101;
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

    int popRight()
    {
        if (qfront == -1)
        {
            return -101;
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

    // Deque dq(5);

    // cout << dq.pushLeft(1) << endl;
    // cout << dq.pushLeft(2) << endl;

    // cout << dq.pushRight(3) << endl;
    // cout << dq.pushRight(4) << endl;

    // cout << dq.popLeft() << endl;
    // cout << dq.popRight() << endl;

    int t, cs = 0;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        cout << "Case " << ++cs << ":" << endl;

        Dequeue dq(n);
        while (m--)
        {
            string s;
            cin >> s;

            if (s == "pushLeft")
            {
                int x;
                cin >> x;
                if (dq.pushLeft(x) == -101)
                {
                    cout << "The queue is full" << endl;
                }
                else
                {
                    cout << "Pushed in left: " << dq.pushLeft(x) << endl;
                }
            }
            else if (s == "pushRight")
            {
                int x;
                cin >> x;
                if (dq.pushRight(x) == -101)
                {
                    cout << "The queue is full" << endl;
                }
                else
                {
                    cout << "Pushed in right: " << dq.pushRight(x) << endl;
                }
            }
            else if (s == "popLeft")
            {
                int x;
                cin >> x;
                if (dq.popLeft() == -101)
                {
                    cout << "The queue is full" << endl;
                }
                else
                {
                    cout << "Popped from right: " << dq.popLeft() << endl;
                }
            }
            else if (s == "popRight")
            {
                int x;
                cin >> x;
                if (dq.popRight() == -101)
                {
                    cout << "The queue is full" << endl;
                }
                else
                {
                    cout << "Popped from right: " << dq.popRight() << endl;
                }
            }
        }
    }

    return 0;
}
