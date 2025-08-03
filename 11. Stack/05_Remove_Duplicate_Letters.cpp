/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (!st.empty() and s[i] == st.top())
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }

        if (st.empty())
        {
            cout << "[ ]" << endl;
        }
        else
        {
            string ans = "";
            while (!st.empty())
            {
                char x = st.top();
                st.pop();
                ans.push_back(x);
            }

            reverse(ans.begin(), ans.end());

            cout << "[ " << ans << " ]" << endl;
        }
    }

    return 0;
}