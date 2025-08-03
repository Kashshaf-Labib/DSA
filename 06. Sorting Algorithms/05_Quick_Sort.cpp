#include <bits/stdc++.h>
#define ll long long
using namespace std;
int cnt;
int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;

    for (int j = l; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
            cnt++;
        }
    }

    swap(arr[i + 1], arr[r]);
    if(arr[i+1]!=arr[r]) cnt++;

    return i + 1;
}

void quickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int pivot = partition(arr, l, r);

        quickSort(arr, l, pivot - 1);
        quickSort(arr, pivot + 1, r);
    }
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int arr[n];

    cnt = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    cout << cnt << endl;

    return 0;
}