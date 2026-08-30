#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isPowerOf2(int n)
{
    return n > 0 && (n & (n - 1)) == 0;
}

int main()
{
    string s = "10100";
    // convert binary to integer
    int val = stoi(s, 0, 2);
    cout << val << endl;

    // only work for power of 2
    if (isPowerOf2(63))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}