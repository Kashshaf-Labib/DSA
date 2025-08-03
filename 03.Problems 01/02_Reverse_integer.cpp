/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    int x;
    cin >> x;
    long long num = 0;
    while (x)
    {
        num = (num * 10) + (num % 10);
        x /= 10;
    }
    if (num > INT_MAX || num < INT_MIN)
    {
        return 0;
    }
    cout << num << endl;

    return 0;
}