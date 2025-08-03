/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 7;
const int inf = 1e9;
vector<int> g[N];
bool vis[N];
int dis[N];
int ans[N];

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> even, odd;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x % 2 == 0)
        {
            even.push_back(i);
        }
        else
        {
            odd.push_back(i);
        }
        if (i - x >= 1)
        {
            g[i - x].push_back(i);
        }
        if (i + x <= n)
        {
            g[i + x].push_back(i);
        }
    }

    for (int i = 0; i < N; i++)
    {
        ans[i] = inf;
        dis[i] = inf;
    }
    queue<int> evenQ;
    for (int i = 0; i < even.size(); i++)
    {
        evenQ.push(even[i]);
        dis[even[i]] = 0;
        vis[even[i]] = true;
    }

    while (!evenQ.empty())
    {
        int u = evenQ.front();
        evenQ.pop();
        for (auto v : g[u])
        {
            if (!vis[v])
            {
                vis[v] = true;
                dis[v] = dis[u] + 1;
                evenQ.push(v);
            }
        }
    }
    for (int i = 0; i < odd.size(); i++)
    {
        ans[odd[i]] = dis[odd[i]];
    }

    for (int i = 0; i < N; i++)
    {
        vis[i] = false;
        dis[i] = inf;
    }

    queue<int> oddQ;
    for (int i = 0; i < odd.size(); i++)
    {
        oddQ.push(odd[i]);
        dis[odd[i]] = 0;
        vis[odd[i]] = true;
    }

    while (!oddQ.empty())
    {
        int u = oddQ.front();
        oddQ.pop();
        for (auto v : g[u])
        {
            if (!vis[v])
            {
                vis[v] = true;
                dis[v] = dis[u] + 1;
                oddQ.push(v);
            }
        }
    }
    for (int i = 0; i < even.size(); i++)
    {
        ans[even[i]] = dis[even[i]];
    }

    for (int i = 1; i <= n; i++)
    {
        if (ans[i] != inf)
        {
            cout << ans[i] << " ";
        }
        else
        {
            cout << -1 << " ";
        }
    }

    return 0;
}