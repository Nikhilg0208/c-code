#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main()
{
    vector<vector<int>> v1{
        {3, 8, 5},
        {1, 7, 4},
        {5, 4, 3},
        {2, 9, 1}};
    sort(v1.begin(), v1.end(), [](auto x, auto y)
         { return x[2] < y[2]; });
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i][0] << " " << v1[i][1] << " " << v1[i][2] << "\n";
    }

    return 0;
}