#include <bits/stdc++.h>
using namespace std;
class base
{
public:
    void fun1()
    {
        cout << "first class"
             << "\n";
    }
};
class first : virtual public base
{
public:
    void fun2()
    {
        cout << "derived class first"
             << "\n";
    }
};
class second : virtual public base
{
public:
    void fun3()
    {
        cout << "derived class second"
             << "\n";
    }
};
class last : public first, public second
{
public:
    void fun4()
    {
        cout << "this is last class"
             << "\n";
    }
};
int main()
{
    last l;
    l.fun4();
    l.fun1();
    l.fun2();
    l.fun3();
    return 0;
}