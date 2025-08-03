/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
string removeDuplicates(string s)
{
    stack<char> stk;
    for (int i = 0; i < s.size(); i++)
    {
        if (stk.empty())
        {
            stk.push(s[i]);
        }
        else if (stk.top() == s[i])
        {
            stk.pop();
        }
        else
        {
            stk.push(s[i]);
        }
    }
    string ans = "";
    while (!stk.empty())
    {
        ans += stk.top();
        stk.pop();
    }
    for (int i = 0, j = ans.size() - 1; i < ans.size() / 2; i++, j--)
    {
        swap(ans[i], ans[j]);
    }
    return ans;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    string s = "aa";
    cout << removeDuplicates(s) << endl;

    return 0;
}