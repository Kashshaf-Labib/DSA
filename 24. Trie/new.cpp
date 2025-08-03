#include <bits/stdc++.h>
using namespace std;

void printpq(priority_queue<int> pq, int x, int y)
{
    cout << "Combine" << x << "," << y << " State:";

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}
int main()
{
    priority_queue<int> pq;

    while (true)
    {
        int x;
        cin >> x;
        if (x == -1)
        {
            break;
        }
        pq.push(x);
    }

    while (pq.size() > 1)
    {
        int top1 = pq.top();
        pq.pop();
        int top2 = pq.top();
        pq.pop();

        if (top1 != top2)
        {
            pq.push(max(top1, top2) - min(top1, top2));
        }
        printpq(pq, top1, top2);
    }

    cout << pq.top() << endl;

    return 0;
}