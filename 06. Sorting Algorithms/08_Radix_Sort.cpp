#include <bits/stdc++.h>
#define ll long long
using namespace std;

void countSort(int arr[], int n, int exp)
{
    int count[10] = {0};

    for (int i = 0; i < n; i++)
    {
        count[arr[i] / exp % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    int output[n];

    for (int i = n - 1; i >= 0; i--)
    {
        output[--count[arr[i] / exp % 10]] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n)
{
    int m = arr[0];
    for (int i = 0; i < n; i++)
    {
        m = max(m, arr[i]);
    }

    for (int exp = 1; m / exp > 0; exp *= 10)
    {
        countSort(arr, n, exp);
    }
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    radixSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}