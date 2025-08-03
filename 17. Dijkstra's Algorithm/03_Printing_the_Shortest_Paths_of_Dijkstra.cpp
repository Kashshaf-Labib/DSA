/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> printingShortestPath(int n, int m, vector<vector<int>> &edges)  //n vertices and m edges
{
    vector<pair<int, int>> adjList[n + 1];

    // Creating the graph:
    for (auto it : edges)
    {
        adjList[it[0]].push_back({it[1], it[2]});
        adjList[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dis(n + 1);
    for (int i = 1; i <= n; i++)
    {
        dis[i] = 1e9;
    }

    vector<int> parent(n + 1);

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    dis[1] = 0;

    pq.push({0, 1});

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int distance = it.first;
        int node = it.second;

        for (auto it : adjList[node])
        {
            int adjNode = it.first;
            int edgeWeight = it.second;
            if (distance + edgeWeight < dis[adjNode])
            {
                dis[adjNode] = distance + edgeWeight;
                parent[adjNode] = node;
                pq.push({dis[adjNode], adjNode});
            }
        }
    }

    if (dis[n] == 1e9)
    {
        return {-1};
    }

    vector<int> shortestPath;

    int node = n;

    while (parent[node] != node)
    {
        shortestPath.push_back(node);
        node = parent[node];
    }
    shortestPath.push_back(1);

    reverse(shortestPath.begin(), shortestPath.end());

    return shortestPath;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}