/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*  Function to implement Bellman Ford
 *   edges: vector of vectors which represents the graph
 *   S: source vertex to start traversing graph with
 *   V: number of vertices
 */
vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
{
    vector<int> dis(V,1e8);

    dis[S] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int weight = it[2];
            if (dis[u] != 1e8 and dis[u] + weight < dis[v])
            {
                dis[v] = dis[u] + weight;
            }
        }
    }

    // Nth iteration to check if the graph contains negative cycle or not:

    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int weight = it[2];

        if (dis[u]!=1e8 and dis[u] + weight < dis[v])
        {
            return {-1};  // if the distance gets updated again, it means the graph has got negative cycle.
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