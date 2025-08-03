/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> dijkstra(int v, vector<vector<int>> adjList[], int s) // Here v denotes total vertices,adjList stores the graph nodes along with their weights
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dis(v);
    for (int i = 0; i < v; i++)
    {
        dis[i] = 1e9;
    }
    dis[s] = 0;
    pq.push({0, s}); // {distance, node} pair

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();

        int distance = it.first;
        int node = it.second;

        for (auto it : adjList[node])
        {
            int edgeWeight = it[1];
            int adjNode = it[0];
            if (distance + edgeWeight < dis[adjNode])
            {
                dis[adjNode] = distance + edgeWeight;
                pq.push({dis[adjNode], adjNode});
            }
        }
    }

    return dis;
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}