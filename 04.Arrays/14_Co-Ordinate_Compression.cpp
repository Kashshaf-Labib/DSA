/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/

// When we work with frequency array, if the size of the array is too large (like 10^8 or greater), the memory limit will exceed,
// so we compress the array by mapping each value of the array with some value starting from 1, in sorted , this is called co-ordinate compression

#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> b = a;
    map<int, int> mp;
    int index = 0;
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++)
    {
        mp[b[i]] = index++;
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = mp[a[i]];
    }

    return 0;
}