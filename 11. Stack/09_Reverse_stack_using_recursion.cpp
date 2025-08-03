/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void recursiontoPutinBottom(stack<int> &stack, int x)
{
    if (stack.empty())
    {
        stack.push(x);
        return;
    }

    int elem = stack.top();
    stack.pop();
    recursiontoPutinBottom(stack, x);
    stack.push(elem);
}
void insertAtBottom(stack<int> &stack, int x)
{
    recursiontoPutinBottom(stack, x);
}

void reverseStack(stack<int> &stack)
{

    if (stack.empty())
    {
        return;
    }
    int topElem = stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom(stack, topElem);
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}