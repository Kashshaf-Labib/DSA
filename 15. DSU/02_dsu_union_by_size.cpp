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
int main()
{

    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    // Check if 3 and 7 are in the same component or not

    if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
    {
        cout << "Same component" << endl;
    }
    else
    {
        cout << "Not same component" << endl;
    }

    ds.unionBySize(3, 7);

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