#include <bits/stdc++.h>
using namespace std;

class parent
{
public:
    virtual void fun1()
    {
        cout << "parent constructor" << endl;
    }
};
class child : public parent
{
public:
    void fun1()
    {
        cout << "child constructor" << endl;
    }
};

int main()
{
    parent *p;
    child obj;
    p = &obj;
    p->fun1(); // if you add virtual keyword in parent class then it will print child class constructor.
    return 0;
}