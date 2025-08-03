/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1005;
vector<int> g[N];
bool vis[N];
int timesVis[N];

void dfs(int u)
{
    vis[u] = true;
    timesVis[u]++;
    for (auto v : g[u])
    {
        if (!vis[v])
        {
            vis[v] = true;
            dfs(v);
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++cs << ": ";
        int k, n, m;
        cin >> k >> n >> m;
        int resident[n];
        for (int i = 1; i <= k; i++)
        {
            cin >> resident[i];
        }
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
        }
        for (int i = 1; i <= k; i++)
        {
            for (int u = 1; u <= n; u++)
            {
                vis[u] = false;
            }
            dfs(resident[i]);
        }

        int ans = 0;

        for (int i = 1; i <= n; i++)
        {
            if (timesVis[i] == k)
            {
                ans++;
            }
        }
        cout << ans << endl;

        for (int i = 1; i <= n; i++)
        {
            g[i].clear();
            timesVis[i] = 0;
        }
    }

    return 0;
}