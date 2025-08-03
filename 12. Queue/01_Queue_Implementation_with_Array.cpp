/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Queue
{
    int *arr;
    int qfront;
    int rear;
    int size;

public:
    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    void enqueue(int value)
    {
        if (rear == size) // queue is full
        {
            cout << "Queue is full" << endl;
            return;
        }
        arr[rear] = value;
        rear++;
    }

    int dequeue()
    {
        if (qfront == rear)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int ans = arr[qfront];
        arr[qfront] = -1;
        qfront++;
        if (qfront == rear)
        {
            qfront = 0;
            rear = 0;
        }
        return ans;
    }

    int front()
    {
        if (qfront == rear)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[qfront];
    }

    int rearr()
    {
        if (qfront == rear)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty()
    {
        if (qfront == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if (rear == size)
        {
            return true;
        }
        return false;
    }

    int sizeofQueue()
    {
        return size;
    }
};

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    Queue q(4);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout << q.dequeue() << endl;

    cout << q.sizeofQueue() << endl;

    return 0;
}