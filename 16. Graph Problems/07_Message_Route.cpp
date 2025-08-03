#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
bool vis[N];
vector<int> g[N];
int dis[N];
int par[N];
int main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    vis[1] = true;
    par[1] = 0;
    dis[1] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : g[u])
        {
            if (!vis[v])
            {
                q.push(v);
                vis[v] = true;
                dis[v] = dis[u] + 1;
                par[v] = u;
            }
        }
    }
    if (dis[n] == 0)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        vector<int> ans;
        int v = n;
        while (v != 0)
        {
            ans.push_back(v);
            v = par[v];
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}