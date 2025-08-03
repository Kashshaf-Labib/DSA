#include <bits/stdc++.h>
#define ll long long
using namespace std;
int arr[10000007];

int findPeak(int arr[], int n)
{
    if (n == 1)
    {
        return arr[0];
    }
    if (arr[0] >= arr[1])
    {
        return arr[0];
    }
    if (arr[n - 2] <= arr[n - 1])
    {
        return arr[n - 1];
    }

    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] >= arr[mid - 1] and arr[mid] >= arr[mid + 1])
        {
            return arr[mid];
        }
        else if (arr[mid] >= arr[mid - 1]) // increasing curve
        {
            low = mid + 1;
        }
        else // decreasing curve or in a lowpoint
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    auto start = chrono::high_resolution_clock::now();

    int peakIndex = findPeak(arr, n);

    cout << "Peak index found at " << peakIndex << endl;

    // auto end = chrono::high_resolution_clock::now();

    // chrono::duration<double> duration = end - start;

    // cout << duration.count() * 10000 << " milliseconds" << endl;

    return 0;
}