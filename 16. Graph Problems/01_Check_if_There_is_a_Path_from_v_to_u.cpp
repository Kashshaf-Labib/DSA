#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
bool vis[N];
vector<int> g[N];
int comps[N];

void dfs(int u, int compNum)
{
    vis[u] = true;
    comps[u] = compNum;
    for (auto v : g[u])
    {
        if (!vis[v])
        {
            dfs(v, compNum);
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, e;
        cin >> n >> e;
        while (e--)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        int compNum = 0;

        for (int i = 1; i <= n; i++)
        {
            compNum++;
            if (!vis[i])
            {
                dfs(i, compNum);
            }
        }

        // Check if there is a path from v to u and u to v:
        int u, v;
        cin >> u >> v;
        if (comps[u] == comps[v])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}