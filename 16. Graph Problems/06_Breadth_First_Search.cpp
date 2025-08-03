#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 105;
bool vis[N];
int dis[N];
int par[N];
vector<int> g[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int u, k;
        cin >> u >> k;
        while (k--)
        {
            int v;
            cin >> v;
            g[u].push_back(v);
        }
    }
    queue<int> q;
    q.push(1);
    vis[1] = true;
    dis[1] = 0;
    par[1] = 0;
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
                par[v] = u;
                dis[v] = dis[u] + 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
        if (dis[i] == 0 and i != 1)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << dis[i] << endl;
        }
    }

    return 0;
}