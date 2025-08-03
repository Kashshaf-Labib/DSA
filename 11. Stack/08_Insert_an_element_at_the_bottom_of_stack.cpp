/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void recursiveSolve(stack<int> &myStack, int x)
{
    if (myStack.empty())
    {
        myStack.push(x);
        return;
    }

    int elem = myStack.top();
    myStack.pop();
    recursiveSolve(myStack, x);
    myStack.push(elem);
}

stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    recursiveSolve(myStack, x);

    return myStack;
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}