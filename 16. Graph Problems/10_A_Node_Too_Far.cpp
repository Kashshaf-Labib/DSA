/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int inf = 1e9;
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    int edges, cs = 0;
    while (cin >> edges and edges)
    {
        map<int, vector<int>> g;
        set<int> nodes;
        while (edges--)
        {
            int u, v;
            cin >> u >> v;
            nodes.insert(u);
            nodes.insert(v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int start, ttl;
        while (cin >> start >> ttl and !(start == 0 and ttl == 0))
        {
            cout << "Case " << ++cs << ": ";
            map<int, int> dis;
            for (auto u : nodes)
            {
                dis[u] = inf;
            }
            queue<int> q;
            q.push(start);
            dis[start] = 0;
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (auto v : g[u])
                {
                    if (dis[u] + 1 < dis[v])
                    {
                        dis[v] = dis[u] + 1;
                        q.push(v);
                    }
                }
            }
            int node_too_far = 0;
            for (auto u : nodes)
            {
                if (dis[u] > ttl)
                {
                    node_too_far++;
                }
            }
            cout << node_too_far << " nodes not reachable from node " << start << " with TTL = " << ttl << "." << endl;
        }
    }

    return 0;
}