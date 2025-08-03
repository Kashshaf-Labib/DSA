/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool isConsiderable(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool checkPalindrome(string s)
{
    int start = 0;
    int end = s.size() - 1;
    while (start <= end)
    {
        if (!isConsiderable(s[start]))
        {
            start++;
        }
        else if (!isConsiderable(s[end]))
        {
            end--;
        }
        else if (tolower(s[start]) == tolower(s[end]))
        {
            start++;
            end--;
        }
        else
        {
            return false;
        }
    }
    return true;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    // cout << checkPalindrome(s);
    cout << s << endl;

    return 0;
}