#include <bits/stdc++.h>
#define ll long long
using namespace std;
int findMaxIndex(vector<vector<int>> &v, int n, int m, int col)
{
    int maxVal = -1;
    int index = -1;

    for (int i = 0; i < n; i++)
    {
        if (v[i][col] > maxVal)
        {
            maxVal = v[i][col];
            index = i;
        }
    }

    return index;
}

pair<int, int> findPeak(vector<vector<int>> v)
{
    int n = v.size();    // rows
    int m = v[0].size(); // columns

    int low = 0, high = m - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int maxRowIndex = findMaxIndex(v, n, m, mid);
        int left = mid - 1 >= 0 ? v[maxRowIndex][mid - 1] : -1;
        int right = mid + 1 < m ? v[maxRowIndex][mid + 1] : -1;

        if (v[maxRowIndex][mid] >= left and v[maxRowIndex][mid] >= right)
        {
            return {maxRowIndex, mid};
        }
        else if (v[maxRowIndex][mid] < left) // peak is on the left of mid
        {
            high = mid - 1;
        }
        else // peak is on the right of mid
        {
            low = mid + 1;
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
            temp.push_back((j + 1) * (i + 1));
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