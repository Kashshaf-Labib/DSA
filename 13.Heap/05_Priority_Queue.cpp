/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Priority_Queue
{
    int *arr;
    int size;
    int totalsize;

public:
    Priority_Queue(int totalsize)
    {
        this->totalsize = totalsize;
        arr[0] = -1;
        size = 0;
    }

    void push(int value)
    {
        if (size == totalsize)
        {
            cout << "Already full" << endl;
            return;
        }

        size++;
        int index = size;
        arr[index] = value;
        while (index > 1)
        {
            int parentIndex = index / 2;
            if (arr[parentIndex] < arr[index])
            {
                swap(arr[parentIndex], arr[index]);
                index = parentIndex;
            }
            else
            {
                return;
            }
        }
    }

    void pop()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        arr[1] = arr[size];
        size--;
        int index = 1;

        while (index <= size)
        {
            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;
            int swapIndex = index;

            if (leftIndex <= size and arr[leftIndex] > arr[swapIndex])
            {
                swapIndex = leftIndex;
            }
            if (rightIndex <= size and arr[rightIndex] > arr[swapIndex])
            {
                swapIndex = rightIndex;
            }
            if (swapIndex != index)
            {
                swap(arr[index], arr[swapIndex]);
                index = swapIndex;
            }
            else
            {
                return;
            }
        }
    }

    int top()
    {
        return arr[1];
    }

    void print()
    {
        for (int i = 1; i <= size; i++)

        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    Priority_Queue pq(5);
    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(4);
    pq.push(5);

    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;

    pq.print();

    return 0;
}