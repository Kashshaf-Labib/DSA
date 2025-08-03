#include <iostream>
#include <bits/stdc++.h>
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

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    // Check if 3 and 7 are in the same component or not

    if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
    {
        cout << "Same component" << endl;
    }
    else
    {
        cout << "Not same component" << endl;
    }

    ds.unionByRank(3, 7);

    // Again, Check if 3 and 7 are in the same component or not

    if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
    {
        cout << "Same component" << endl;
    }
    else
    {
        cout << "Not same component" << endl;
    }

    return 0;
}