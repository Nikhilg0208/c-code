#include <bits/stdc++.h>
using namespace std;
vector<string> v;
void powerSet(string str, int index, string curr, int n)
{
    if (index == n)
    {
        v.push_back(curr);
        return;
    }
    powerSet(str, index + 1, curr + str[index], n);
    powerSet(str, index + 1, curr, n);
}
int main()
{
    string str = "abcd";
    string curr = "";
    int n = str.length();
    powerSet(str, 0, curr, n);
    for (auto z : v)
    {
        cout << z << "\n";
    }
    return 0;
}