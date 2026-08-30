#include <bits/stdc++.h>
using namespace std;

class FloydWarshall
{
public:
    vector<vector<int>> shortestPath(
        int V,
        vector<vector<int>> matrix)
    {
        int INF = 100000000;

        // Floyd-Warshall
        for (int k = 0; k < V; k++)
        {
            for (int i = 0; i < V; i++)
            {
                for (int j = 0; j < V; j++)
                {
                    // No path through k
                    if (matrix[i][k] == INF ||
                        matrix[k][j] == INF)
                    {
                        continue;
                    }

                    // Relaxation
                    matrix[i][j] =
                        min(matrix[i][j],
                            matrix[i][k] + matrix[k][j]);
                }
            }
        }

        return matrix;
    }
};

int main()
{
    // Test Case 1
    {
        int V = 4;

        int INF = 100000000;

        vector<vector<int>> matrix = {
            {0, 3, 10, 7},
            {8, 0, 2, 9},
            {5, 1, 0, 4},
            {2, 6, 3, 0}};

        FloydWarshall obj;

        vector<vector<int>> result =
            obj.shortestPath(V, matrix);

        cout << "Test Case 1:" << endl;

        for (auto row : result)
        {
            for (auto value : row)
            {
                cout << value << " ";
            }

            cout << endl;
        }

        cout << "Expected:" << endl;

        cout << "0 3 5 7" << endl;
        cout << "5 0 2 6" << endl;
        cout << "5 1 0 4" << endl;
        cout << "2 3 5 0" << endl;
    }

    // Test Case 2
    {
        int V = 3;

        vector<vector<int>> matrix = {
            {0, 4, 11},
            {2, 0, 3},
            {5, 1, 0}};

        FloydWarshall obj;

        vector<vector<int>> result =
            obj.shortestPath(V, matrix);

        cout << "\nTest Case 2:" << endl;

        for (auto row : result)
        {
            for (auto value : row)
            {
                cout << value << " ";
            }

            cout << endl;
        }

        cout << "Expected:" << endl;

        cout << "0 4 7" << endl;
        cout << "2 0 3" << endl;
        cout << "3 1 0" << endl;
    }

    // Test Case 3
    // Negative Weight Cycle
    {
        int V = 3;

        int INF = 100000000;

        vector<vector<int>> matrix = {
            {0, 1, INF},
            {INF, 0, -1},
            {-1, INF, 0}};

        FloydWarshall obj;

        vector<vector<int>> result =
            obj.shortestPath(V, matrix);

        cout << "\nTest Case 3:" << endl;

        // Check for negative weight cycle
        bool negativeCycle = false;

        for (int i = 0; i < V; i++)
        {
            if (result[i][i] < 0)
            {
                negativeCycle = true;
                break;
            }
        }

        if (negativeCycle)
        {
            cout << "Negative Weight Cycle" << endl;
        }
        else
        {
            for (auto row : result)
            {
                for (auto value : row)
                {
                    cout << value << " ";
                }

                cout << endl;
            }
        }

        cout << "Expected: Negative Weight Cycle"
             << endl;
    }

    return 0;
}