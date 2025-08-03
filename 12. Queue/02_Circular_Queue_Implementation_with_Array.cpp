/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Circularqueue
{
    int *arr;
    int size;
    int qfront;
    int rear;

public:
    Circularqueue(int size)
    {
        this->size = size;
        arr = new int[size];
        qfront = -1;
        rear = -1;
    }

    void enqueue(int value)
    {
        // in case array is full
        if ((qfront == 0 and rear == size - 1) || (rear == (qfront - 1) % (size - 1)))
        {
            cout << "Queue is full" << endl;
        }
        // First element to push
        else if (qfront == -1)
        {
            qfront = 0;
            rear = 0;
            arr[rear] = value;
        }
        else if (rear == size - 1 and qfront != 0)  //circular condition
        {
            rear = 0;
            arr[rear] = value;
        }
        else //normal push
        {
            rear++;
            arr[rear] = value;
        }
    }

    int deque()
    {
        if (qfront == -1)  //empty queue
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else if (qfront == rear) //single element
        {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront = -1;
            rear = -1;
            return ans;
        }
        else if (qfront == size - 1) // circular condition
        {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront = 0;
            return ans;
        }
        else //normal pop
        {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            return ans;
        }
    }

    bool empty()
    {
        if (qfront == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int front()
    {
        if (qfront == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else
        {
            return arr[qfront];
        }
    }
};

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    Circularqueue cq(3);
    cout << cq.empty() << endl;

    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);

    cout << cq.deque() << endl;
    cout << cq.deque() << endl;

    return 0;
}