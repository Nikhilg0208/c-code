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
class derived1 : public first
{
public:
    void fun2()
    {
        cout << "derived class 1"
             << "\n";
    }
};
class derived2 : public first
{
public:
    void fun3()
    {
        cout << "derived class 2";
    }
};
int main()
{
    derived1 d;
    d.fun1();
    d.fun2();
    return 0;
}