#include <bits/stdc++.h>
#define ll long long
using namespace std;

void bucketSort(float arr[], int size)
{
    vector<vector<float>> bucket(size, vector<float>());

    for (int i = 0; i < size; i++)
    {
        int index = size * arr[i];
        bucket[index].push_back(arr[i]);
    }

    for (int i = 0; i < size; i++)
    {
        if(!bucket[i].empty())
        sort(bucket[i].begin(), bucket[i].end());
    }


    int k = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < bucket[i].size(); j++)
        {
            arr[k++] = bucket[i][j];
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    float arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bucketSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}