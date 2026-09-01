#include <bits/stdc++.h>
using namespace std;
class Mergesort
{
public:
    void merging(vector<int> &arr, int low, int mid, int high)
    {
        int firstSize = mid - low + 1, secondSize = high - mid;
        int left[firstSize], right[secondSize];

        for (int i = 0; i < firstSize; i++)
            left[i] = arr[low + i];
        for (int j = 0; j < secondSize; j++)
            right[j] = arr[mid + 1 + j];

        int indexone = 0, indexsec = 0, indexmerge = low;
        while (indexone < firstSize && indexsec < secondSize)
        {
            if (left[indexone] <= right[indexsec])
            {
                arr[indexmerge] = left[indexone];
                indexone++;
            }
            else
            {
                arr[indexmerge] = right[indexsec];
                indexsec++;
            }
            indexmerge++;
        }

        
        while (indexone < firstSize)
        {
            arr[indexmerge] = left[indexone];
            indexone++;
            indexmerge++;
        }
        while (indexsec < secondSize)
        {
            arr[indexmerge] = right[indexsec];
            indexsec++;
            indexmerge++;
        }
    }
    void mergesortFunc(vector<int> &arr, int low, int high)
    {
        if (low < high)
        {
            int mid = low + (high - low) / 2;
            mergesortFunc(arr, low, mid);
            mergesortFunc(arr, mid + 1, high);
            merging(arr, low, mid, high);
        }
    }
    void sort(vector<int> &adj)
    {
        mergesortFunc(adj, 0, adj.size() - 1);
    }
};

int main()
{
    vector<int> adj = {100, 5, 6, 4, 3, 3, 4, 5, 6, 7};
    Mergesort obj;
    obj.sort(adj);
    for (auto val : adj)
        cout << val << " ";
    cout << endl;
    return 0;
}