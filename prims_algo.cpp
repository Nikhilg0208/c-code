#include <bits/stdc++.h>
using namespace std;

class Prims
{
public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>>
            pq;

        vector<int> vis(V, 0);

        // {weight, node}
        pq.push({0, 0});

        int sum = 0;

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int node = it.second;
            int wt = it.first;

            if (vis[node] == 1)
                continue;

            // Add it to the MST
            vis[node] = 1;
            sum += wt;

            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int edW = it[1];

                if (!vis[adjNode])
                {
                    pq.push({edW, adjNode});
                }
            }
        }

        return sum;
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

        vector<vector<int>> adj[V];

        for (auto it : edges)
        {
            vector<int> tmp(2);

            tmp[0] = it[1];
            tmp[1] = it[2];
            adj[it[0]].push_back(tmp);

            tmp[0] = it[0];
            tmp[1] = it[2];
            adj[it[1]].push_back(tmp);
        }

        Prims obj;
        int sum = obj.spanningTree(V, adj);

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

        vector<vector<int>> adj[V];

        for (auto it : edges)
        {
            vector<int> tmp(2);

            tmp[0] = it[1];
            tmp[1] = it[2];
            adj[it[0]].push_back(tmp);

            tmp[0] = it[0];
            tmp[1] = it[2];
            adj[it[1]].push_back(tmp);
        }

        Prims obj;
        int sum = obj.spanningTree(V, adj);

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

        vector<vector<int>> adj[V];

        for (auto it : edges)
        {
            vector<int> tmp(2);

            tmp[0] = it[1];
            tmp[1] = it[2];
            adj[it[0]].push_back(tmp);

            tmp[0] = it[0];
            tmp[1] = it[2];
            adj[it[1]].push_back(tmp);
        }

        Prims obj;
        int sum = obj.spanningTree(V, adj);

        cout << "Test Case 3: "
             << sum << " | Expected: 8" << endl;
    }

    return 0;
}