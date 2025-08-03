/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void heapifyMax(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n and arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= n and arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapifyMax(arr, n, largest);
    }
}

void heapSort(int arr[], int size)
{
    while (size > 1)
    {
        swap(arr[1], arr[size]);
        size--;
        heapifyMax(arr, size, 1);
    }
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    // given a random array

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    // heapifyMax the whole array

    for (int i = n / 2; i >= 1; i--)
    {
        heapifyMax(arr, n, i);
    }

    cout << "Heap Max array:";

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Heap sort the array

    heapSort(arr, n);

    // after heap sort
    cout << "after heap sort:";
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}