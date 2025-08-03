/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 205;
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

    int n;
    while (cin >> n and n)
    {
        int m;
        cin >> m;
        while (m--)
        {
            int u, v;
            ++u, ++v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        for (int i = 1; i <= n; i++)
        {
            col[i] = 0;
            vis[i] = false;
        }

        okay = true;
        dfs(1);
        if (okay)
        {
            cout << "BICOLORABLE." << endl;
        }
        else
        {
            cout << "NOT BICOLORABLE." << endl;
        }

        for (int i = 1; i <= n; i++)
        {
            g[i].clear();
        }
    }

    return 0;
}