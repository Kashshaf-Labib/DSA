#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
vector<int> g[N];
bool vis[N];
int cats[N];
int consec_cats[N];
int m;
int ans = 0;

void dfs(int u, int parent)
{
    vis[u] = true;
    if (cats[u] == 1)
    {
        consec_cats[u] = consec_cats[parent] + 1;
    }
    else
    {
        consec_cats[u] = 0;
    }

    if (consec_cats[u] > m)
    {
        return;
    }
    bool is_leaf = true;
    for (auto v : g[u])
    {
        if (!vis[v])
        {
            dfs(v, u);
            is_leaf = false;
        }
    }
    if (is_leaf)
    {
        ans++;
    }
}
int main()
{
    int n;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> cats[i];
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);

    cout << ans << endl;
    return 0;
}