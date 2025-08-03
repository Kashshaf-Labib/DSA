#include <bits/stdc++.h>
#define ll long long
using namespace std;

pair<int, int> findPeak(vector<vector<int>> &v)
{
    int row = v.size();
    int col = v[0].size();

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            bool isPeak = true;
            if (i > 0)
            {
                if (v[i][j] < v[i - 1][j])
                {
                    isPeak = false;
                }
            }
            if (i < row - 1)
            {
                if (v[i][j] < v[i + 1][j])
                {
                    isPeak = false;
                }
            }
            if (j > 0)
            {
                if (v[i][j] < v[i][j - 1])
                {
                    isPeak = false;
                }
            }
            if (j < col - 1)
            {
                if (v[i][j] < v[i][j + 1])
                {
                    isPeak = false;
                }
            }
            if (isPeak)
            {
                return {i, j};
            }
        }
    }

    return {-1, -1};
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> v;

    int row, col;
    cin >> row >> col;

    for (int i = 0; i < row; i++)
    {
        vector<int> temp;
        for (int j = 0; j < col; j++)
        {
            temp.push_back((i + 1) * (j + 1));
        }
        v.push_back(temp);
    }

    auto start = chrono::high_resolution_clock::now();

    auto peakIndex = findPeak(v);

    cout << "Peak index found at " << peakIndex.first << " " << peakIndex.second << endl;

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = end - start;

    cout << duration.count() * 10000 << " milliseconds" << endl;

    // auto it = findPeak(v);

    // cout << it.first << " " << it.second << endl;

    return 0;
}