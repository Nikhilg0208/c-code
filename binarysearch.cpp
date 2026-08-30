#include <iostream>
using namespace std;
int main()
{
    int a[] = {3, 1, 2, 4};
    int i = 0, j = 3;
    int ask;
    cin >> ask;
    while (i <= j)
    {
        int mid = i + (j - i) / 2;
        if (a[mid] > ask)
            j = mid - 1;
        else if (a[mid] < ask)
            i = mid + 1;
        else
        {
            cout << mid;
            return mid;
        }
    }
    cout << "not a valid search"
         << "\n";
    return 0;
}