#include <bits/stdc++.h>
#define ll long long
using namespace std;
int arr[10000007];

int peakFind(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if ((i == 0 or arr[i - 1] <= arr[i]) and (i == n - 1 or arr[i] >= arr[i + 1]))
        {
            return i+1;
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }

    auto start = chrono::high_resolution_clock::now();

    int peakIndex = peakFind(arr, n);

    cout << "Peak index found at " << peakIndex << endl;

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = end - start;

    cout << duration.count() * 10000 << " milliseconds" << endl;

    return 0;
}