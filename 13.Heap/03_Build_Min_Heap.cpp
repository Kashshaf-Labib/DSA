/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void heapifyMin(vector<int> &arr, int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n and arr[left] < arr[smallest])  // not left <=n because 0 indexed 
    {
        smallest = left;
    }
    if (right < n and arr[right] < arr[smallest])
    {
        smallest = right;
    }
    if (smallest != i)
    {
        swap(arr[smallest], arr[i]);
        heapifyMin(arr, n, smallest);
    }
}

vector<int> buildMinHeap(vector<int> &arr)
{
    int n = arr.size();

    // leaf nodes: (n/2) to (n-1)

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapifyMin(arr, n, i);
    }

    return arr;
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}