/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int c = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << j;
        }
        for (int k = 1; k <= c; k++)
        {
            cout << "*";
        }
        c += 2;
        for (int l = n - i + 1; l >= 1; l--)
        {
            cout << l;
        }
        cout << endl;
    }

    return 0;
}