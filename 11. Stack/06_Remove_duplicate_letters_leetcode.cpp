/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

string removeDuplicateLetters(string s)
{
    stack<char> st;
    bool visited[26] = {false};
    int freq[26] = {0};

    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i] - 'a']++;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (visited[s[i] - 'a'])
        {
            freq[s[i] - 'a']--;
            continue;
        }

        while (!st.empty() and st.top() - 'a' > s[i] - 'a' and freq[st.top() - 'a'] > 0)
        {
            visited[st.top() - 'a'] = false;
            st.pop();
        }

        st.push(s[i]);
        visited[s[i] - 'a'] = true;
        freq[s[i] - 'a']--;
    }

    string ans = "";

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    cout << removeDuplicateLetters("aaaeeebbcc");

    return 0;
}