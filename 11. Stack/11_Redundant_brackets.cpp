/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool findOut(stack<char> &stack)
{
    bool okay = false;
    while (!stack.empty() and stack.top() != '(')
    {
        okay = true;
        stack.pop();
    }
    if (!stack.empty())
    {
        stack.pop();
    }
    return okay;
}

bool findRedundantBrackets(string &s)
{
    bool isRedundant = false;
    stack<char> stack;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ')')
        {
            if (!findOut(stack))
            {
                isRedundant = true;
                break;
            }
        }
        else if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            stack.push(s[i]);
        }
    }

    return isRedundant;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    if (!findRedundantBrackets(s))
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }

    return 0;
}