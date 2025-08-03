#include <bits/stdc++.h>
#define ll long long
using namespace std;

int ternarySearch(int arr[], int n, int key)
{
    int l = 0, r = n - 1;

    while (l <= r)
    {
        int m1 = (2 * l + r) / 3;
        int m2 = (l + 2 * r) / 3;

        if (arr[m1] == key)
        {
            return m1;
        }
        if (arr[m2] == key)
        {
            return m2;
        }

        if (key < arr[m1])
        {
            r = m1 - 1;
        }
        else if (key > arr[m2])
        {
            l = m2 + 1;
        }
        else
        {
            l = m1 + 1;
            r = m2 - 1;
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}