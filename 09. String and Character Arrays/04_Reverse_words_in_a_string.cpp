/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
string reverseWords(string s)
{
    string ans = "";
    int i = 0;
    int n = s.size();
    while (i < n)
    {
        while (s[i] == ' ' && i < n)
        {
            i++;
        }
        if (i == n)
        {
            break;
        }
        int j = i;
        while (j < n && s[j] != ' ')
        {
            j++;
        }
        string sub = s.substr(i, j - i);
        if (ans.size() == 0)
        {
            ans = sub;
        }
        else
        {
            ans = sub + " " + ans;
        }
        i = j + 1;
    }
    return ans;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    string s = "ab bc";
    cout << reverseWords(s) << endl;

    return 0;
}