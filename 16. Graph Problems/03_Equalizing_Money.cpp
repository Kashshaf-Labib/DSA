#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
bool vis[N];
vector<int> g[N];
long long moneyPerhead[N];
long long money = 0;
int person = 0;
void dfs(int u)
{
    person += 1;
    money += moneyPerhead[u];
    vis[u] = true;
    for (auto v : g[u])
    {
        if (!vis[v])
        {
            dfs(v);
        }
    }
}
int main()
{
    int t, tc = 1;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> moneyPerhead[i];
        }
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        bool okay = true;

        set<int> st;

        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                money = 0;
                person = 0;
                dfs(i);
            }
            if (money % person == 0)
            {
                st.insert(money / person);
            }
            else
            {
                okay = false;
                break;
            }
        }

        cout << "Case " << tc++ << ": ";
        if (!okay or st.size() > 1)
        {
            cout << "No" << endl;
        }
        else if (okay and st.size() == 1)
        {
            cout << "Yes" << endl;
        }
        for (int i = 1; i <= n; i++)
        {
            vis[i] = false;
            g[i].clear();
        }
    }
    return 0;
}