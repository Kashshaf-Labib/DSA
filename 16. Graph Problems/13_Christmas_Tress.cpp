/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    map<int, int> dis;
    queue<int> q;
    vector<int> ansArray;
    while (n--)
    {
        int x;
        cin >> x;
        q.push(x);
        dis[x] = 0;
    }
    ll ans = 0;
    while (m > 0 and !q.empty())
    {
        int u = q.front();
        q.pop();
        if (dis.find(u - 1) == dis.end() and m > 0)
        {
            q.push(u - 1);
            ansArray.push_back(u - 1);
            dis[u - 1] = dis[u] + 1;
            ans += dis[u - 1];
            m--;
        }
        if (dis.find(u + 1) == dis.end() and m > 0)
        {
            q.push(u + 1);
            ansArray.push_back(u + 1);
            dis[u + 1] = dis[u] + 1;
            ans += dis[u + 1];
            m--;
        }
    }

    cout << ans << endl;
    for (auto x : ansArray)
    {
        cout << x << " ";
    }

    return 0;
}