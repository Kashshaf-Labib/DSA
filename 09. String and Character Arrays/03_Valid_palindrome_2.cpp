/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool validPalindrome(string s)
{
    int c1 = 0, c2 = 0;
    int start = 0, end = s.size() - 1;
    while (start < end)
    {
        if (s[start] == s[end])
        {
            start++;
            end--;
        }
        else
        {
            start++;
            c1++;
        }
    }
    start = 0, end = s.size() - 1;
    while (start < end)
    {
        if (s[start] == s[end])
        {
            start++;
            end--;
        }
        else
        {
            end--;
            c2++;
        }
    }
    if (c1 == 1 || c2 == 1)
    {
        return true;
    }
    if (c1 == 0 || c2 == 0)
    {
        return true;
    }
    return false;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    cout << validPalindrome(s) << endl;

    return 0;
}