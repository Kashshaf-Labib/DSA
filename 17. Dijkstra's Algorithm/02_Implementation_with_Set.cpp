/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> dijkstra(int v, vector<vector<int>> adjList[], int s) // Here v denotes total vertices,adjList stores the graph nodes along with their weights
{
    set<pair<int, int>> st;

    vector<int> dis(v, 1e9);
    dis[s] = 0;
    st.insert({0, s});
    while (!st.empty())
    {
        auto it = *(st.begin());
        int distance = it.first;
        int node = it.second;
        st.erase(it);
        for (auto it : adjList[node])
        {
            int adjNode = it[0];
            int edgeWeight = it[1];
            if (distance + edgeWeight < dis[adjNode])
            {
                if (dis[adjNode] != 1e9)
                {
                    st.erase({dis[adjNode], adjNode});
                }
                dis[adjNode] = distance + edgeWeight;
                st.insert(dis[adjNode], adjNode);
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