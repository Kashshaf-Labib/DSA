/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
char getMaxOcccuringChar(string s)
{
    unordered_map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }
    int maxx = -5;
    char ans;
    for (auto x : mp)
    {
        if (x.second > maxx)
        {
            ans = x.first;
            maxx = x.second;
        }
    }
    return ans;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    string s = "Hello world ooooooooo";
    cout << getMaxOcccuringChar(s) << endl;

    return 0;
}