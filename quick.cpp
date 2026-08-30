#include <bits/stdc++.h>
using namespace std;
class Quicksort
{
public:
    int partition(vector<int> &arr, int low, int high)
    {
        int pivot = arr[low];
        int pivotIndex = low;
        for (int i = low + 1; i <= high; i++)
        {
            if (arr[i] < pivot)
            {
                pivotIndex++;
                swap(arr[pivotIndex], arr[i]);
            }
        }
        swap(arr[pivotIndex], arr[low]);
        return pivotIndex;
    }
    void quicksortFunc(vector<int> &arr, int low, int high)
    {
        if (low < high)
        {
            int pivot = partition(arr, low, high);
            quicksortFunc(arr, low, pivot - 1);
            quicksortFunc(arr, pivot + 1, high);
        }
    }
    void sort(vector<int> &adj)
    {
        quicksortFunc(adj, 0, adj.size() - 1);
    }
};

int main()
{
    vector<int> adj = {4, 5, 1, 3, 7, 9, 8, 11};
    Quicksort obj;
    obj.sort(adj);
    for (auto val : adj)
        cout << val << " ";
    return 0;
}