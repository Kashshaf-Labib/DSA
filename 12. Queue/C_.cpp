/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
queue<int> q;

int ping(int t)
{
    q.push(t);
    while (q.size() and t - q.front() > 3000)
    {
        q.pop();
    }

    return q.size();
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    cout << ping(1) << "\n";
    cout << ping(2) << "\n";
    cout << ping(3) << "\n";
    cout << ping(4) << "\n";
    cout << ping(3001) << "\n";
    cout << ping(3002) << "\n";
    cout << ping(3003) << "\n";
    cout << ping(6003) << "\n";
    cout << ping(10003) << "\n";

    return 0;
}