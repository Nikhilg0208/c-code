#include <bits/stdc++.h>
using namespace std;
class base
{
public:
    void fun1()
    {
        cout << "base class"
             << "\n";
    }
};
class deri : public base
{
public:
    void fun2()
    {
        cout << "derived class"
             << "\n";
    }
};
class derideri : public deri
{
public:
    void fun3()
    {
        cout << "super derived class"
             << "\n";
    }
};
int main()
{
    derideri obj;
    obj.fun1();
    obj.fun2();
    obj.fun3();
    return 0;
}