/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std; 

void insertionSort(int n,vector<int> &arr)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        while (j >= 0 and arr[j] > arr[j + 1])
        {
            swap(arr[j], arr[j + 1]);
            j--;
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    insertionSort(n, v);

    for (auto x : v)
    {
        cout << x << " ";
    }

    return 0;
}