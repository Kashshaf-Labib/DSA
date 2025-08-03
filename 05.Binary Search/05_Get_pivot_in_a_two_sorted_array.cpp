/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/

// Pivot when the array can be sorted into two line:

#include <bits/stdc++.h>
#define ll long long
using namespace std;
int getPivotIndex(vector<int> &arr)
{
    int n = arr.size();
    int start = 0;
    int end = n - 1;
    int mid = (start + end) / 2;
    while (start < end)
    {
        if (arr[mid] >= arr[0])
        {
            start = mid + 1;
        }
        else if (arr[mid] < arr[0])
        {
            end = mid;
        }
        mid = (start + end) / 2;
    }
    return start;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << getPivotIndex(v) << endl;

    return 0;
}