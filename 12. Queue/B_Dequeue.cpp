/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Dequeue
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    Dequeue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    int pushLeft(int value)
    {
        if ((front == 0 and rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            return -101;
        }

        else if (front == -1)
        {
            front = 0;
            rear = 0;
            arr[front] = value;
            return value;
        }
        else if (front == 0)
        {
            front = size - 1;
            arr[front] = value;
            return value;
        }
        else
        {
            front--;
            arr[front] = value;
            return value;
        }
    }
    int pushRight(int value)
    {
        if ((front == -1 and rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            return -101;
        }

        else if (front == -1)
        {
            front = 0;
            rear = 0;
            arr[rear] = value;
            return value;
        }
        else if (rear == size - 1)
        {
            rear = 0;
            arr[rear] = value;
            return value;
        }
        else
        {
            rear++;
            arr[rear] = value;
            return value;
        }
    }
    int popLeft()
    {
        int ans = -101;
        if (front == -1)
        {
            ans = -101;
        }
        else if (front == rear)
        {
            ans = arr[front];
            arr[front] = -1;
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            ans = arr[front];
            arr[front] = -1;
            front = 0;
        }
        else
        {
            ans = arr[front];
            arr[front] = -1;
            front++;
        }
        return ans;
    }
    int popRight()
    {
        int ans = -101;
        if (front == -1)
        {
            ans = -101;
        }
        else if (front == rear)
        {
            ans = arr[rear];
            arr[rear] = -1;
            front = rear = -1;
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
};
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

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
            if (s == "pushLeft" || s == "pushRight")
            {
                int x;
                cin >> x;
                if (s == "pushLeft")
                {
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
                    if (dq.pushRight(x) == -101)
                    {
                        cout << "The queue is full" << endl;
                    }
                    else
                    {
                        cout << "Pushed in right: " << dq.pushRight(x) << endl;
                    }
                }
            }
        }
    }

    return 0;
}