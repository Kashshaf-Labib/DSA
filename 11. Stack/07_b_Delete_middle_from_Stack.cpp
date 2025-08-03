/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void deleteMiddle(stack<int> &inputStack, int N)
{
    int count = 0;
    vector<int> v;
    while (!inputStack.empty())
    {
        count++;
        int x = inputStack.top();
        inputStack.pop();
        if (count != (N / 2) + 1)
        {
            v.push_back(x);
        }
    }

    for (int i = v.size() - 1; i >= 0; i--)
    {
        inputStack.push(v[i]);
    }
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    deleteMiddle(st, 4);

    while (!st.empty())
    {
        int x = st.top();
        st.pop();
        cout << x << " ";
    }

    return 0;
}