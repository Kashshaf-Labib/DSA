/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1005, inf = 1e9;
string s[N];
int n, m;
queue<pair<int, int>> q;
pair<int, int> par[N][N];
int dis[N][N];

bool is_valid(int i, int j)
{
    return (i >= 0 and i < n and j >= 0 and j < m);
}

int direction_i[] = {1, 0, -1, 0};
int direction_j[] = {0, 1, 0, -1};

void bfs(int start_i, int start_j)
{
    par[start_i][start_j] = make_pair(0, 0);
    dis[start_i][start_j] = 0;
    q.push(make_pair(start_i, start_j));

    while (!q.empty())
    {
        auto pr = q.front();
        q.pop();

        int i = pr.first, j = pr.second;
        for (int k = 0; k < 4; ++k)
        {
            int next_i = i + direction_i[k];
            int next_j = j + direction_j[k];
            if (is_valid(next_i, next_j) and s[next_i][next_j] != '#' and dis[i][j] + 1 < dis[next_i][next_j])
            {
                par[next_i][next_j] = make_pair(i, j);
                dis[next_i][next_j] = dis[i][j] + 1;
                q.push(make_pair(next_i, next_j));
            }
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

    int start_i = -1, start_j = -1, end_i = -1, end_j = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == 'A')
            {
                start_i = i, start_j = j;
            }
            if (s[i][j] == 'B')
            {
                end_i = i, end_j = j;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dis[i][j] = inf;
        }
    }

    bfs(start_i, start_j);

    int ans = dis[end_i][end_j];
    if (ans == inf)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        cout << ans << endl;
        vector<pair<int, int>> path;
        auto current = make_pair(end_i, end_j);
        auto start = make_pair(start_i, start_j);
        while (current != start)
        {
            path.push_back(current);
            current = par[current.first][current.second];
        }
        path.push_back(start);
        reverse(path.begin(), path.end());

        for (int k = 0; k < path.size() - 1; k++)
        {
            int diff_i = path[k].first - path[k + 1].first;
            int diff_j = path[k].second - path[k + 1].second;

            if (diff_i == +1)
            {
                cout << 'U';
            }
            else if (diff_i == -1)
            {
                cout << 'D';
            }
            else if (diff_j == +1)
            {
                cout << 'L';
            }
            else if (diff_j == -1)
            {
                cout << 'R';
            }
        }
    }

    return 0;
}