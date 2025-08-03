/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solveRecursive(stack<int> &inputStack, int size, int count)
{
    if (count == size / 2)
    {
        inputStack.pop();
        return;
    }

    int x = inputStack.top();
    inputStack.pop();

    solveRecursive(inputStack, size, count + 1);
    inputStack.push(x);
}

void deleteMiddle(stack<int> &inputStack, int N)
{
    int count = 0;
    solveRecursive(inputStack, N, count);
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    stack<int> st;
    st.push(7);
    st.push(8);
    st.push(9);

    deleteMiddle(st, 2);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}