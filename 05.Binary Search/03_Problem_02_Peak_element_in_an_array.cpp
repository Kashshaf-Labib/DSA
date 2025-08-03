/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int peakIndexInMountainArray(vector<int> &arr)
{
    int n = arr.size();
    int start = 0;
    int end = n - 1;
    int ans = -1;
    while (start < end)
    {
        if (arr[start + 1] >= arr[start])
        {
            start += 1;
        }
        if (arr[end - 1] >= arr[end])
        {
            end -= 1;
        }
        ans = start;
    }
    return ans;
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
    cout << peakIndexInMountainArray(v);

    return 0;
}