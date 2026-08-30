#include <bits/stdc++.h>
using namespace std;

class Dijkstra
{
public:
    vector<int> shortestPath(
        int V,
        vector<vector<int>> adj[],
        int S)
    {
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>>
            pq;

        vector<int> dist(V, INT_MAX);

        // Distance from source to itself
        dist[S] = 0;

        // {distance, node}
        pq.push({0, S});

        while (!pq.empty())
        {
            auto [wt, node] = pq.top();
            pq.pop();

            // Skip outdated entries
            if (wt > dist[node])
                continue;

            for (auto it : adj[node])
            {
                int conNode = it[0];
                int weight = it[1];

                // Relaxation
                if (dist[node] + weight < dist[conNode])
                {
                    dist[conNode] = dist[node] + weight;

                    pq.push({dist[conNode], conNode});
                }
            }
        }

        return dist;
    }
};

int main()
{
    // Test Case 1
    {
        int V = 5;

        vector<vector<int>> adj[V];

        // Edge: 0 <-> 1, weight = 2
        adj[0].push_back({1, 2});
        adj[1].push_back({0, 2});

        // Edge: 0 <-> 2, weight = 4
        adj[0].push_back({2, 4});
        adj[2].push_back({0, 4});

        // Edge: 1 <-> 2, weight = 1
        adj[1].push_back({2, 1});
        adj[2].push_back({1, 1});

        // Edge: 1 <-> 3, weight = 7
        adj[1].push_back({3, 7});
        adj[3].push_back({1, 7});

        // Edge: 2 <-> 4, weight = 3
        adj[2].push_back({4, 3});
        adj[4].push_back({2, 3});

        int S = 0;

        Dijkstra obj;

        vector<int> result =
            obj.shortestPath(V, adj, S);

        cout << "Test Case 1: ";

        for (int distance : result)
        {
            cout << distance << " ";
        }

        cout << endl;

        cout << "Expected: 0 2 3 9 6"
             << endl;
    }

    // Test Case 2
    {
        int V = 4;

        vector<vector<int>> adj[V];

        adj[0].push_back({1, 1});
        adj[1].push_back({0, 1});

        adj[0].push_back({2, 4});
        adj[2].push_back({0, 4});

        adj[1].push_back({2, 2});
        adj[2].push_back({1, 2});

        adj[1].push_back({3, 6});
        adj[3].push_back({1, 6});

        adj[2].push_back({3, 3});
        adj[3].push_back({2, 3});

        int S = 0;

        Dijkstra obj;

        vector<int> result =
            obj.shortestPath(V, adj, S);

        cout << "\nTest Case 2: ";

        for (int distance : result)
        {
            cout << distance << " ";
        }

        cout << endl;

        cout << "Expected: 0 1 3 6"
             << endl;
    }

    // Test Case 3
    {
        int V = 3;

        vector<vector<int>> adj[V];

        // Edge: 0 -> 1, weight = 2
        adj[0].push_back({1, 2});

        // Edge: 0 -> 2, weight = 5
        adj[0].push_back({2, 5});

        // Edge: 2 -> 1, weight = -10
        adj[2].push_back({1, -10});

        int S = 0;

        Dijkstra obj;

        vector<int> result =
            obj.shortestPath(V, adj, S);

        cout << "\nTest Case 3: ";

        for (int distance : result)
        {
            cout << distance << " ";
        }

        cout << endl;

        cout << "Expected: 0 -5 5" << endl;
    }

    return 0;
}