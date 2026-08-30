#include <bits/stdc++.h>
using namespace std;

class BellmanFord
{
public:
    vector<int> shortestPath(
        int V,
        vector<vector<int>> edges,
        int S)
    {
        vector<int> dist(V, 1e8);

        dist[S] = 0;

        // Relax all edges V - 1 times
        for (int i = 0; i < V - 1; i++)
        {
            for (auto it : edges)
            {
                int u = it[0];  // Starting point
                int v = it[1];  // Ending point
                int wt = it[2]; // Edge weight

                if (dist[u] != 1e8 &&
                    dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // Nth relaxation to check negative cycle
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if (dist[u] != 1e8 &&
                dist[u] + wt < dist[v])
            {
                return {-1};
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

        vector<vector<int>> edges = {
            {0, 1, 2},
            {0, 2, 4},
            {1, 2, -1},
            {1, 3, 7},
            {2, 4, 3},
            {3, 4, 1}};

        int S = 0;

        BellmanFord obj;

        vector<int> result =
            obj.shortestPath(V, edges, S);

        cout << "Test Case 1: ";

        for (int distance : result)
        {
            cout << distance << " ";
        }

        cout << endl;

        cout << "Expected: 0 2 1 9 4"
             << endl;
    }

    // Test Case 2
    {
        int V = 4;

        vector<vector<int>> edges = {
            {0, 1, 4},
            {0, 2, 5},
            {1, 2, -3},
            {2, 3, 4}};

        int S = 0;

        BellmanFord obj;

        vector<int> result =
            obj.shortestPath(V, edges, S);

        cout << "\nTest Case 2: ";

        for (int distance : result)
        {
            cout << distance << " ";
        }

        cout << endl;

        cout << "Expected: 0 4 1 5"
             << endl;
    }

    // Test Case 3
    {
        int V = 3;

        vector<vector<int>> edges = {
            {0, 1, 1},
            {1, 2, -1},
            {2, 0, -1}};

        int S = 0;

        BellmanFord obj;

        vector<int> result =
            obj.shortestPath(V, edges, S);

        cout << "\nTest Case 3: ";

        if (result.size() == 1 && result[0] == -1)
        {
            cout << "Negative Weight Cycle";
        }
        else
        {
            for (int distance : result)
            {
                cout << distance << " ";
            }
        }

        cout << endl;

        cout << "Expected: Negative Weight Cycle"
             << endl;
    }

    return 0;
}