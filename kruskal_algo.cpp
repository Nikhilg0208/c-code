#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Kruskal
{
public:
    int spanningTree(int V, vector<vector<int>> edges)
    {
        vector<pair<int, pair<int, int>>> v1;

        for (auto edge : edges)
        {
            int a = edge[0];
            int b = edge[1];
            int wt = edge[2];

            v1.push_back({wt, {a, b}});
        }

        DisjointSet ds(V);

        sort(v1.begin(), v1.end());

        int mstwt = 0;

        for (auto vv1 : v1)
        {
            int wt = vv1.first;
            int a = vv1.second.first;
            int b = vv1.second.second;

            if (ds.findUPar(a) != ds.findUPar(b))
            {
                mstwt += wt;
                ds.unionBySize(a, b);
            }
        }

        return mstwt;
    }
};

int main()
{
    // Test Case 1
    {
        int V = 5;

        vector<vector<int>> edges = {
            {0, 1, 2},
            {0, 2, 1},
            {1, 2, 1},
            {2, 3, 2},
            {3, 4, 1},
            {4, 2, 2}};

        Kruskal obj;
        int sum = obj.spanningTree(V, edges);

        cout << "Test Case 1: "
             << sum << " | Expected: 5" << endl;
    }

    // Test Case 2
    {
        int V = 4;

        vector<vector<int>> edges = {
            {0, 1, 10},
            {0, 2, 6},
            {0, 3, 5},
            {1, 3, 15},
            {2, 3, 4}};

        Kruskal obj;
        int sum = obj.spanningTree(V, edges);

        cout << "Test Case 2: "
             << sum << " | Expected: 19" << endl;
    }

    // Test Case 3
    {
        int V = 3;

        vector<vector<int>> edges = {
            {0, 1, 5},
            {1, 2, 3},
            {0, 2, 10}};

        Kruskal obj;
        int sum = obj.spanningTree(V, edges);

        cout << "Test Case 3: "
             << sum << " | Expected: 8" << endl;
    }

    return 0;
}