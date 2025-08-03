#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 25;
string s[N];
int m, n;
int direction_i[4] = {1, 0, -1, 0};
int direction_j[4] = {0, 1, 0, -1};
bool vis[N][N];
int ans = 0;

bool is_valid(int i, int j)
{
    return i >= 0 and i < n and j >= 0 and j < m;
}

void dfs(int i, int j)
{
    vis[i][j] = true;
    ans++;
    for (int k = 0; k < 4; k++)
    {
        int next_i = i + direction_i[k];
        int next_j = j + direction_j[k];
        if (is_valid(next_i, next_j) and s[next_i][next_j] == '.')
        {
            if (!vis[next_i][next_j])
            {
                dfs(next_i, next_j);
            }
        }
    }
}
int main()
{
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        cin >> m >> n;
        int x, y;
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (s[i][j] == '@')
                {
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        dfs(x, y);
        cout << ans << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                vis[i][j] = false;
            }
        }
        ans = 0;
    }

    return 0;
}