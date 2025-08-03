/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> ninjaAndSortedArrays(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
    vector<int> sortedArray;
    for (int i = 0; i < m; i++)
    {
        if (arr1[i] != 0)
            sortedArray.push_back(arr1[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (arr2[i] != 0)
            sortedArray.push_back(arr2[i]);
    }
    sort(sortedArray.begin(), sortedArray.end());

    return sortedArray;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    vector<int> arr1(m);
    vector<int> arr2(n);
    for (int i = 0; i < m; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }
    vector<int> ans = ninjaAndSortedArrays(arr1, arr2, m, n);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}