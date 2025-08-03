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
    int Solve(int n, vector<vector<int>> &edge)
    {
        DisjointSet ds(n);
        int extraEdges = 0;
        for (auto it : edge)
        {
            int u = it[0];
            int v = it[1];
            if (ds.findUltimateParent(u) == ds.findUltimateParent(v))
            {
                extraEdges++;
            }
            else
            {
                ds.unionBySize(u, v);
            }
        }

        int connectedcomponents = 0;

        for (int i = 0; i < n; i++)
        {
            if (ds.findUltimateParent(i) == i)
            {
                connectedcomponents++;
            }
        }
        int ans = connectedcomponents - 1;
        if (extraEdges < ans)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};
int main()
{
    return 0;
}