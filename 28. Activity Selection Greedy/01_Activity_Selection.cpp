/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/

// given some tasks and their starting and ending time, find out the maximum task one can perform if
// he can perform only one task at a time.
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool compareBySecond(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
    return a.second < b.second;
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    int tasks;
    cin >> tasks;

    vector<pair<int, int>> pr;

    for (int i = 0; i < tasks; i++)
    {
        int start, end;
        cin >> start >> end;
        pr.push_back({start, end});
    }

    sort(pr.begin(), pr.end(), compareBySecond);

    int ans = 1;
    int end = pr[0].second;

    for (int i = 1; i < tasks; i++)
    {
        if (pr[i].first >= end)
        {
            ans++;
            end = pr[i].second;
        }
    }

    cout << ans << endl;

    return 0;
}