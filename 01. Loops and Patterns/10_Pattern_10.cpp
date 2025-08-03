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
    char ch = 'A';
    for (char i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << ch << " ";
        }
        cout << endl;
        ch++;
    }

    return 0;
}