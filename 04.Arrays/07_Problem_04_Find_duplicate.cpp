/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int duplicateNumber(int *arr, int size)
{
    int ans = 0;
    sort(arr, arr + size);
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            ans = arr[i];
        }
    }
    return ans;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    // int arr[4];
    // for (int i = 0; i < 4; i++)
    // {
    //     cin >> arr[i];
    // }
    // cout << duplicateNumber(arr, 4);

    // or
    int arr[4] = {1, 2, 1, 3};
    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        ans = ans ^ arr[i];
    }
    for (int i = 0; i < 4; i++)
    {
        ans = ans ^ i;
    }
    cout << ans << endl;

    return 0;
}