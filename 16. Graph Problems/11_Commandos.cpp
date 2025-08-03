/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 105;
vector<int> g[N];
bool vis[N];
int disFromStart[N];
int disFromEnd[N];
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++cs << ": ";
        int n;
        cin >> n;
        int edges;
        cin >> edges;
        while (edges--)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int start, end;
        cin >> start >> end;
        queue<int> q1;
        q1.push(start);
        vis[start] = true;
        disFromStart[start] = 0;
        while (!q1.empty())
        {
            int u = q1.front();
            q1.pop();
            for (auto v : g[u])
            {
                if (!vis[v])
                {
                    vis[v] = true;
                    q1.push(v);
                    disFromStart[v] = disFromStart[u] + 1;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            vis[i] = false;
        }
        queue<int> q2;
        q2.push(end);
        vis[end] = true;
        disFromEnd[end] = 0;
        while (!q2.empty())
        {
            int u = q2.front();
            q2.pop();
            for (auto v : g[u])
            {
                if (!vis[v])
                {
                    vis[v] = true;
                    q2.push(v);
                    disFromEnd[v] = disFromEnd[u] + 1;
                }
            }
        }
        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, disFromStart[i] + disFromEnd[i]);
        }
        cout << ans << endl;

        for (int i = 0; i < n; i++)
        {
            g[i].clear();
        }
        for (int i = 0; i < n; i++)
        {
            vis[i] = false;
        }
    }

    return 0;
}