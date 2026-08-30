#include <bits/stdc++.h>
using namespace std;
class first
{
public:
    void fun1()
    {
        cout << "first class"
             << "\n";
    }
};
class second
{
public:
    void fun2()
    {
        cout << "second class"
             << "\n";
    }
};
class derived : public first, public second
{
public:
    void fun3()
    {
        cout << "this is the derived class";
    }
};
int main()
{
    derived d;
    d.fun1();
    d.fun2();
    d.fun3();
    return 0;
}