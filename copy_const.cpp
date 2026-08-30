#include <bits/stdc++.h>
using namespace std;
class copyconstuct
{
private:
    int a;
    int *p;

public:
    copyconstuct(int x)
    {
        a = x;
        p = new int[a];
        p[0] = 1;
    }
    copyconstuct(copyconstuct &obj)
    {
        a = obj.a;
        p = new int[a];
    }
};
int main()
{
    copyconstuct obj(10);
    copyconstuct obj1(obj);
    return 0;
}
