/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool isPossible(vector<int> &stalls, int k, int mid)
{
    int cowCount = 1;
    int lastPosition = stalls[0];
    for (int i = 0; i < stalls.size(); i++)
    {
        if (stalls[i] - lastPosition >= mid)
        {
            cowCount++;
            if (cowCount > k)
            {
                return false;
            }
        }
    }
    return true;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int ans = 0;
    int start = 0;
    int end = *max_element(stalls.begin(), stalls.end()) - *min_element(stalls.begin(), stalls.end());
    int mid = start + ((end - start) / 2);
    while (start <= end)
    {
        if (isPossible(stalls, k, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + ((end - start) / 2);
    }
    return ans;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}