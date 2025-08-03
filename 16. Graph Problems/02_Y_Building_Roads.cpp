#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
bool vis[N];
vector<int> g[N];
vector<int> comphead;

void dfs(int u)
{
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
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, comps = 0;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            comps++;
            comphead.push_back(i);
            dfs(i);
        }
    }

    int path = comphead.size();

    cout << comps - 1 << endl;
    for (int i = 0; i < path - 1; i++)
    {
        cout << comphead[i] << " " << comphead[i + 1] << endl;
    }

    return 0;
}