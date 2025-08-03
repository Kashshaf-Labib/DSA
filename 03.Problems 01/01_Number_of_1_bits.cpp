/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    uint32_t n;
    cin >> n;
    int c = 0;
    string s = to_string(n);
    for (int i = 0; i < s.size(); i++)
    {
        if (((int)s[i]) & 1)
        {
            c++;
        }
    }
    cout << c;

    return 0;
}