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
    int decimal = 0;
    int base = 1;
    while (n)
    {
        int digit = n % 10;
        if (digit == 1)
        {
            decimal += (digit * base);
        }
        n /= 10;
        base *= 2;
    }
    cout << decimal;

    return 0;
}