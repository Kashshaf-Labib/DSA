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
    string s;
    while (x)
    {
        if (x & 1)
        {
            s += '0';
        }
        else
        {
            s += '1';
        }

        x >>= 1;
    }
    string binstr;

    for (int i = s.size() - 1; i >= 0; i--)
    {
        binstr += s[i];
    }
    int binary = stoi(binstr);
    int dec = 0;
    int base = 1;
    while (binary)
    {
        int last_digit = binary % 10;

        binary /= 10;

        dec += base * last_digit;

        base *= 2;
    }

    cout << dec;

    // another approach:
    // int n;
    // cin >> n;
    // int bin = 0;
    // while (n)
    // {
    //     int bit = n & 1;
    //     bin = (bin * 10) + bit;
    //     n >>= 1;
    // }
    // int ans = 0;
    // int base = 1;
    // while (bin)
    // {
    //     int digit = bin % 10;
    //     if (digit == 0)
    //     {
    //         digit = 1;
    //     }
    //     else if (digit == 1)
    //     {
    //         digit = 0;
    //     }
    //     ans += (digit * base);
    //     bin /= 10;
    //     base *= 2;
    // }

    
    return 0;
}