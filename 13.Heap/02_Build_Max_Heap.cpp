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
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i >= 1; i--)
    {
        heapifyMax(arr, n, i);
    }

    cout << "After max heapify" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}