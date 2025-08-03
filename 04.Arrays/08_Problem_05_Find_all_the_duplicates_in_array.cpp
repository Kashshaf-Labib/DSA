/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> findDuplicates(vector<int> &nums)
{
    map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }

    vector<int> ans;

    for (auto x : mp)
    {
        if (x.second > 1)
        {
            ans.push_back(x.first);
        }
    }
    return ans;
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
    vector<int> ans = findDuplicates(v);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}