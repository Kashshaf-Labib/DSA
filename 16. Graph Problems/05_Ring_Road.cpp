#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 105;
vector<pair<int, int>> g[N];
bool vis[N];
int total = 0;
void dfs(int u, int parent)
{
    vis[u] = true;
    for (auto [v, cost] : g[u])
    {
        if (!vis[v])
        {
            total += cost;
            dfs(v, u);
        }
        else if (v == 1 and parent != 1)
        {
            total += cost;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        sum += cost;
        g[u].push_back({v, 0});
        g[v].push_back({u, cost});
    }

    dfs(1, 0);

    cout << min(total, sum - total) << endl;

    return 0;
}