#include <bits/stdc++.h>
using namespace std;
class Mergesort
{
public:
    void merge(vector<int> &adj, int start, int mid, int end)
    {
        int firstArraySize = mid - start + 1, secondArraySize = end - mid;
        int arr1[firstArraySize], arr2[secondArraySize];
        for (int i = 0; i < firstArraySize; i++)
        {
            arr1[i] = adj[start + i];
        }
        for (int j = 0; j < secondArraySize; j++)
        {
            arr2[j] = adj[mid + j + 1];
        }
        int indexone = 0, indexsec = 0, indexmerge = start;
        while (indexone < firstArraySize && indexsec < secondArraySize)
        {
            if (arr1[indexone] < arr2[indexsec])
            {
                adj[indexmerge] = arr1[indexone];
                indexmerge++;
                indexone++;
            }
            else
            {
                adj[indexmerge] = arr2[indexsec];
                indexsec++;
                indexmerge++;
            }
        }
        while (indexone < firstArraySize)
        {
            adj[indexmerge] = arr1[indexone];
            indexmerge++;
            indexone++;
        }
        while (indexsec < secondArraySize)
        {
            adj[indexmerge] = arr2[indexsec];
            indexsec++;
            indexmerge++;
        }
    }
    void mergesortFunc(vector<int> &adj, int start, int end)
    {
        if (start < end)
        {
            int mid = start + (end - start) / 2;
            mergesortFunc(adj, start, mid);
            mergesortFunc(adj, mid + 1, end);
            merge(adj, start, mid, end);
        }
    }

    void sort(vector<int> &adj)
    {

        mergesortFunc(adj, 0, adj.size() - 1);
    }
};
int main()
{
    vector<int> adj = {4, 5, 6, 4, 3, 3, 4, 5, 6, 7, 1, 2, 3, 5, 6, -9, -10};
    int size = adj.size();
    Mergesort obj;
    obj.sort(adj);
    for (int i = 0; i < size; i++)
    {
        cout << adj[i] << " ";
    }
    return 0;
}