/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void sortInsert(stack<int> &stack, int x)
{
    if (stack.empty())
    {
        stack.push(x);
        return;
    }
    else if (stack.top() <= x)
    {
        stack.push(x);
        return;
    }
    int topElem = stack.top();
    stack.pop();
    sortInsert(stack, x);
    stack.push(topElem);
}

void sortStack(stack<int> &stack)
{
    if (stack.empty())
    {
        return;
    }
    int x = stack.top();
    stack.pop();
    sortStack(stack);
    sortInsert(stack, x);
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}