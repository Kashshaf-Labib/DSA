/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    // Priority Queue following max heap:

    priority_queue<int> max_pq;

    max_pq.push(1);
    max_pq.push(2);
    max_pq.push(3);

    //int max_size = max_pq.size();
    // for (int i = 0; i < max_size; i++)
    // {
    //     cout << max_pq.top() << " ";
    //     max_pq.pop();
    // }
    // cout << endl;

    // Priority Queue following min heap:

    priority_queue<int, vector<int>, greater<int>> min_pq;

    min_pq.push(10);
    min_pq.push(9);
    min_pq.push(8);

    // int min_size = min_pq.size();
    // for (int i = 0; i < min_size; i++)
    // {
    //     cout << min_pq.top() << " ";
    //     min_pq.pop();
    // }
    // cout << endl;

    return 0;
}