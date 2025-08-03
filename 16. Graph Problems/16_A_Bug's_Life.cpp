/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2005;
vector<int> g[N];
bool vis[N];
int col[N];
bool okay;

void dfs(int u)
{
    vis[u] = true;
    for (auto v : g[u])
    {
        if (!vis[v])
        {
            col[v] = col[u] ^ 1;
            dfs(v);
        }
        else if (vis[v])
        {
            if (col[v] == col[u])
            {
                okay = false;
            }
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Scenario #" << ++tc << ":" << endl;
        int n, m;
        cin >> n >> m;
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        okay = true;
        for (int i = 1; i <= n; i++)
        {
            vis[i] = false;
            col[i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                dfs(i);
            }
        }
        if (okay)
        {
            cout << "No suspicious bugs found!" << endl;
        }
        else
        {
            cout << "Suspicious bugs found!" << endl;
        }

        for (int i = 1; i <= n; i++)
        {
            g[i].clear();
        }
    }

    return 0;
}