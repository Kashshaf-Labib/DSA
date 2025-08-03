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
        bool ans = true;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' or s[i] == '{' or s[i] == '[')
            {
                st.push(s[i]);
            }
            else if (s[i] == ')')
            {
                if (!st.empty() and st.top() != '(')
                {
                    ans = false;
                    break;
                }
                else
                {
                    st.pop();
                }
            }
            else if (s[i] == '}')
            {
                if (!st.empty() and st.top() != '{')
                {
                    ans = false;
                    break;
                }
                else
                {
                    st.pop();
                }
            }
            else if (s[i] == ']')
            {
                if (!st.empty() and st.top() != '[')
                {
                    ans = false;
                    break;
                }
                else
                {
                    st.pop();
                }
            }
        }

        if (ans and st.empty())
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}