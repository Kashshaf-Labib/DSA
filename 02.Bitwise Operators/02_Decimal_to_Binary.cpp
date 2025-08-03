/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n; // For positive numbers
    int binary = 0;
    int i = 0;
    while (n)
    {
        int bit = n & 1;

        binary += (bit * pow(10, i));
        i++;
        n >>= 1;
    }
    cout << binary << endl;

    return 0;
}