#include <bits/stdc++.h>
using namespace std;
class parent
{
public:
    parent()
    {
        cout << "parent constructor" << endl;
    }
};
class child : public parent
{
public:
    child()
    {
        cout << "child constructor" << endl;
    }
};

int main()
{
    child obj;
    return 0;
}