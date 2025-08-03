/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool uniqueOccurrences(vector<int> &arr)
{
    map<int, int> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
    }
    set<int> st;
    for (auto x : mp)
    {
        st.insert(x.second);
    }
    if (mp.size() == st.size())
    {
        return true;
    }
    return false;
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    vector<int> vec;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vec.push_back(x);
    }
    cout << uniqueOccurrences(vec);

    return 0;
}