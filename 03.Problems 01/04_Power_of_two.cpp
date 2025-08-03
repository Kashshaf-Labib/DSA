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
    if (n <= 0)
    {
        cout << false;
        return 0;
    }
    while (n > 1)
    {
        if (n % 2 != 0)
        {
            cout << false;
            return 0;
        }
        n /= 2;
    }

    cout << true;

    return 0;
}