/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
void sort012(int *arr, int n)
{
    //   Write your code here\

    // Three pointer approach:

    int current = 0;
    int zeropos = 0;
    int twopos = n - 1;
    while (current < twopos)
    {
        if (arr[current] == 0 && current < twopos)
        {
            swap(arr[current], arr[zeropos]);
            zeropos++;
            current++;
        }
        else if (arr[current] == 2 && current < twopos)
        {
            swap(arr[current], arr[twopos]);
            twopos--;
        }
        else if (current < twopos)
        {
            current++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort012(arr, n);

    return 0;
}