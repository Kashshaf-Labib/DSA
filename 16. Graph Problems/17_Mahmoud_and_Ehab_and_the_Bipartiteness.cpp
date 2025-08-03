/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 9;
vector<int> g[N];
bool vis[N];
int col[N];

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
    }
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {

        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);

    int zeroCol = 0, oneCol = 0;
    for (int i = 1; i <= n; i++)
    {
        if (col[i] == 0)
        {
            zeroCol++;
        }
        else
        {
            oneCol++;
        }
    }

    cout << (1LL * zeroCol * oneCol) - (n - 1) << endl;

    return 0;
}