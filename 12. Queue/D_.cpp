/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
queue<int> q;
// Push into the Stack
void push_s(int x)
{
    q.push(x);
    for (int i = 0; i < q.size() - 1; i++)
    {
        q.push(q.front());
        q.pop();
    }
}
// Removes the element on top of the stack.
void pop_s()
{
    q.pop();
}
// Get the top element.
int top_s()
{
    return q.front();
}
// Return whether the stack is empty.
bool empty_s()
{
    return q.empty();
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    push_s(10);
    cout << top_s() << endl;
    push_s(20);
    cout << top_s() << endl;
    pop_s();
    cout << top_s() << endl;
    push_s(100);
    cout << top_s() << endl;
    cout << empty_s() << endl;
    pop_s();
    pop_s();
    cout << empty_s() << endl;

    return 0;
}