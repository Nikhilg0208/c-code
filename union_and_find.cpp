#include <bits/stdc++.h>
using namespace std;
class dissjointset
{
private:
    vector<int> size, parent;

public:
    dissjointset(int n)
    {
        size.resize(n + 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            size[i] = 1;
            parent[i] = i;
        }
    }

    int findUpr(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }
        return parent[node] = findUpr(parent[node]);
    }

    bool isSameParent(int u, int v)
    {
        return findUpr(u) == findUpr(v);
    }

    int unionBySize(int u, int v)
    {
        int upperu = findUpr(u), upperv = findUpr(v);
        if (size[upperu] > size[upperv])
        {
            parent[upperv] = upperu;
            size[upperv] += size[upperu];
        }
        else
        {
            parent[upperu] = upperv;
            size[upperu] += size[upperv];
        }
    }
};
int main()
{
    dissjointset obj(9);
    obj.unionBySize(2, 4);
    obj.unionBySize(4, 5);
    obj.unionBySize(1, 2);
    obj.unionBySize(2, 3);
    obj.unionBySize(7, 8);
    cout << obj.isSameParent(1, 6) << "";
    return 0;
}