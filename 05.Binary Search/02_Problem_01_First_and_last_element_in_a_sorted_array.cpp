/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    // Write your code here
    pair<int, int> pr;
    int i1 = -1, i2 = -1;

    // Linear Search:

    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] == k)
    //     {
    //         if (!startfound)
    //         {
    //             startfound = true;
    //             i1 = i;
    //         }
    //         else if (startfound)
    //         {
    //             if (i > i2)
    //             {
    //                 i2 = i;
    //             }
    //         }
    //     }
    // }

    // Binary Search:

    int start = 0;
    int end = n - 1;
    int mid = (start + end) / 2;
    while (start <= end)
    {
        if (arr[mid] == k)
        {
            i1 = mid;
            end = mid - 1;
        }
        else if (arr[mid] < k)
        {
            start = mid + 1;
        }
        else if (arr[mid] > k)
        {
            end = mid - 1;
        }
        mid = (start + end) / 2;
    }
    start = 0;
    end = n - 1;
    while (start <= end)
    {
        if (arr[mid] == k)
        {
            i2 = mid;
            start = mid + 1;
        }
        else if (arr[mid] < k)
        {
            start = mid + 1;
        }
        else if (arr[mid] > k)
        {
            end = mid - 1;
        }
        mid = (start + end) / 2;
    }
    pr = make_pair(i1, i2);
    return pr;

    // for total number of occurence = (last index -first index)+1;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    pair<int, int> pr = firstAndLastPosition(v, n, k);

    cout << pr.first << " " << pr.second << endl;

    return 0;
}