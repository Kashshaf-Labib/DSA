/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Heap // Max Heap
{
    int *arr;
    int heapsize;
    int size; // current size at any given time

public:
    Heap(int heapsize)
    {
        this->heapsize = heapsize;
        arr = new int[heapsize];
        arr[0] = -1;
        size = 0;
    }

    void insert(int value)
    {
        if (size == heapsize)
        {
            cout << "heap full" << endl;
            return;
        }
        size++;
        int index = size;
        arr[index] = value;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[index] > arr[parent])
            {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void remove()
    {
        if (size == 0)
        {
            cout << "Nothing to delete" << endl;
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
            // if (leftIndex <= size and arr[leftIndex] > arr[index] and arr[leftIndex] >= arr[rightIndex])
            // {
            //     swap(arr[leftIndex], arr[index]);
            //     index = leftIndex;
            // }
            // else if (rightIndex <= size and arr[rightIndex] > arr[index] and arr[rightIndex] >= arr[leftIndex])
            // {
            //     swap(arr[rightIndex], arr[index]);
            //     index = rightIndex;
            // }
            // else
            // {
            //     return;
            // }

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

    Heap heap(50);
    heap.insert(50);
    heap.insert(55);
    heap.insert(53);
    heap.insert(52);
    heap.insert(54);
    heap.print();

    heap.remove();

    heap.print();

    return 0;
}