/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool isPossible(vector<int> &weights, int days, int mid) // Here mid acts as the minimum weight of the ship
{
    int weightSum = 0;
    int dayCount = 1;
    for (int i = 0; i < weights.size(); i++)
    {
        if (weightSum + weights[i] <= mid)
        {
            weightSum += weights[i];
        }
        else
        {
            dayCount++;
            if (dayCount > days || weights[i] > mid)
            {
                return false;
            }
            weightSum = weights[i];
        }
    }
    return true;
}

int shipWithinDays(vector<int> &weights, int days)
{
    int ans = -1;
    int start = 0;
    int end = accumulate(weights.begin(), weights.end(), 0);
    int mid = start + ((end - start) / 2);
    while (start <= end)
    {
        if (isPossible(weights, days, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + ((end - start) / 2);
    }
    return ans;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    int n, days;
    cin >> n >> days;
    vector<int> weights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }
    cout << shipWithinDays(weights, days);

    return 0;
}