/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUltimateParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ultParu = findUltimateParent(u);
        int ultParv = findUltimateParent(v);
        if (ultParu == ultParv)
        {
            return;
        }
        if (rank[ultParu] < rank[ultParv])
        {
            parent[ultParu] = ultParv;
        }
        else if (rank[ultParu] > rank[ultParv])
        {
            parent[ultParv] = ultParu;
        }
        else
        {
            parent[ultParv] = ultParu;
            rank[ultParu]++;
        }
    }
};

int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<pair<int, pair<int, int>>> edges;
    vector<pair<int, int>> mst;

    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            int adjNode = it[0];
            int weight = it[1];
            int node = i;

            edges.push_back({weight, {node, adjNode}});
        }
    }

    sort(edges.begin(), edges.end());

    DisjointSet ds(V);

    int mstSum = 0;

    for (auto it : edges)
    {
        int weight = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if (ds.findUltimateParent(u) != ds.findUltimateParent(v))
        {
            mstSum += weight;
            mst.push_back({u, v});
            ds.unionByRank(u, v);
        }
    }

    // printing the mst:
    // for (auto it : mst)
    // {
    //     cout << it.first << " " << it.second << endl;
    // }

    return mstSum;
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}