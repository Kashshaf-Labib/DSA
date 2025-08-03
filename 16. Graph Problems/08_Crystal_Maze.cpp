#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 505;
string s[N];
int vis[N][N];
int m, n, ans = 0;

bool is_valid(int x, int y)
{
    return x >= 0 and x < m and y >= 0 and y < n;
}

int direction_x[4] = {1, 0, -1, 0};
int direction_y[4] = {0, 1, 0, -1};

void dfs(int i, int j, int entry)
{
    vis[i][j] = entry;
    if (s[i][j] == 'C')
    {
        ans++;
    }
    for (int k = 0; k < 4; k++)
    {
        int next_i = i + direction_x[k];
        int next_j = j + direction_y[k];
        if (is_valid(next_i, next_j) and !vis[next_i][next_j] and s[next_i][next_j] != '#')
        {
            dfs(next_i, next_j, entry);
        }
    }
}
int main()
{
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": " << endl;
        int q;
        cin >> m >> n >> q;
        for (int i = 0; i < m; i++)
        {
            cin >> s[i];
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                vis[i][j] = false;
            }
        }
        long long total[505 * 505] = {0};
        int entry = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j] and s[i][j] != '#')
                {
                    ans = 0;
                    dfs(i, j, entry);
                    total[entry] = ans;
                    entry++;
                }
            }
        }

        while (q--)
        {
            int x, y;
            cin >> x >> y;
            --x, --y;
            cout << total[vis[x][y]] << endl;
        }
    }
    return 0;
}