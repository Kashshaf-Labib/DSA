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
    int a = 0;
    int b = 1;
    cout << a << " " << b << " ";
    for (int i = 1; i <= n - 2; i++)
    {
        int nextNum = a + b;
        cout << nextNum << " ";
        a = b;
        b = nextNum;
    }

    return 0;
}