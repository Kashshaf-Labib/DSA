/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N, k;
vector<int> arr;
vector<vector<int>> sumTable;
vector<vector<int>> maxTable;

void buildTable()
{
    for (int i = 0; i < N; i++)
    {
        sumTable[i][0] = arr[i];
        maxTable[i][0] = arr[i];
    }

    for (int j = 1; j <= k; j++)
    {
        for (int i = 0; i + (1 << j) <= N; i++)
        {
            sumTable[i][j] = sumTable[i][j - 1] + sumTable[i + (1 << (j - 1))][j - 1];
            maxTable[i][j] = max(maxTable[i][j - 1], maxTable[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int rangeMaxQuery(int L, int R)
{
    int j = log2(R - L + 1);

    return max(maxTable[L][j], maxTable[R - (1 << j) + 1][j]);
}

int rangeSum(int L, int R)
{
    int sum = 0;
    for (int j = k; j >= 0; j--)
    {
        if (L + (1 << j) - 1 <= R)
        {
            sum += sumTable[L][j];
            L += (1 << j);
        }
    }

    return sum;
}

void solve()
{
    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    k = ceil(log2(N)) + 1;
    sumTable.assign(N, vector<int>(k + 1, 0));
    maxTable.assign(N, vector<int>(k + 1, 0));

    buildTable();

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            cout << sumTable[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << endl;

    cout << "Range Max of 0 to 3 is ";
    cout << rangeMaxQuery(0, 3);

    cout << endl;

    cout << "Range sum of range 1 to 3 is ";
    cout << rangeSum(1, 3);

    cout << endl;
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}