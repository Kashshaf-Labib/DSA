/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int findUnique(int *arr, int size)
{
    map<int, int> mp;

    for (int i = 0; i < size; i++)
    {
        mp[arr[i]]++;
    }
    int unique;
    for (auto x : mp)
    {
        if (x.second == 1)
        {
            unique = x.first;
        }
    }
    return unique;
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
    int unique = findUnique(arr, n);
    cout << unique;

    // Another approach:


    // int ans = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     ans = ans ^ arr[i];
    // }
    // cout << ans;

    return 0;
}