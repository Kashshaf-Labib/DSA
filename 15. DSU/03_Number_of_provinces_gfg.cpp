#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
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

    void unionBySize(int u, int v)
    {
        int ultParu = findUltimateParent(u);
        int ultParv = findUltimateParent(v);
        if (ultParu == ultParv)
        {
            return;
        }
        if (size[ultParu] < size[ultParv])
        {
            parent[ultParu] = ultParv;
            size[ultParv] += size[ultParu];
        }
        else
        {
            parent[ultParv] = ultParu;
            size[ultParu] += size[ultParv];
        }
    }
};

class Solution
{
public:
    int numProvinces(vector<vector<int>> adj, int V)
    {
        DisjointSet ds(V);
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adj[i][j] == 1)
                {
                    ds.unionBySize(i, j);
                }
            }
        }

        int count = 0;

        for (int i = 0; i < V; i++)
        {
            if (ds.findUltimateParent(i) == i)
            {
                count++;
            }
        }

        return count;
    }
};
int main()
{
    return 0;
}