/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int findMinimumCost(string str)
{

    stack<char> st;
    if (str.size() % 2 != 0)
    {
        return -1;
    }

    int cost = 0;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '}')
        {
            if (!st.empty() and st.top() != '{')
            {
                cost++;
                st.pop();
            }
            else if (!st.empty() and st.top() == '{')
            {
                st.pop();
            }
            else if (st.empty())
            {
                cost++;
            }
        }
        else
        {
            st.push(str[i]);
        }
    }

    return (st.size() / 2) + (st.size() % 2) + (cost / 2) + (cost % 2);

}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    cout << findMinimumCost("}}}}}{");

    return 0;
}