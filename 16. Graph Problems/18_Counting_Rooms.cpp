/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1005;
bool vis[N][N];
string s[N];
int n, m;

bool is_valid(int i, int j)
{
    return (i >= 0 and i < n and j >= 0 and j < m);
}

int direction_i[] = {1, 0, -1, 0};
int direction_j[] = {0, 1, 0, -1};

void dfs(int i, int j)
{
    vis[i][j] = true;

    for (int k = 0; k < 4; k++)
    {
        int next_i = i + direction_i[k];
        int next_j = j + direction_j[k];

        if (is_valid(next_i, next_j) and !vis[next_i][next_j] and s[next_i][next_j] == '.')
        {
            dfs(next_i, next_j);
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '.' and !vis[i][j])
            {
                dfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}