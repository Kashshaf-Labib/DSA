/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/


/*Prim's Algorithm to find the sum of weight of minimum spanning tree and the edges of the MST given a graph of V vertices */

/*Here adj[i] contains vectors of size 2, where the first integer in that vector denotes
the end of the edge and the second integer denotes the edge weight. */

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int sumOfMSTWeight(int V, vector<vector<int>> adj[])
{
    vector<int> vis(V, 0);      // to track the visited vertices
    vector<pair<int, int>> mst; // to store the edges of the MST
    // min heap to store the vertices and their weights (weight,(node,parent))
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {0, -1}});

    int sum = 0;
    while (pq.size())
    {
        int dis = pq.top().first;
        int node = pq.top().second.first;
        int parent = pq.top().second.second;
        pq.pop();

        if (vis[node])
        {
            continue;
        }

        if (parent != -1)
        {
            mst.push_back({node, parent});
        }

        vis[node] = 1;
        sum += dis;

        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edgeW = it[1];

            if (!vis[adjNode])
            {
                pq.push({edgeW, {adjNode, node}});
            }
        }
    }

    // printing the MST
    for (auto it : mst)
    {
        cout << it.first << " " << it.second << endl;
    }

    return sum;
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}