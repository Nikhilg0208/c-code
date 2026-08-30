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
    virtual void fun2() = 0; // pure virtual function.  if class having a pure virtual function that class is called abstract class.
};
class deri : public base
{
public:
    void fun2() // what is pure virtual function? those function must be overrided by derived class called pure virtual function.
    {
        cout << "derived class"
             << "\n";
    }
};
int main()
{
    deri obj;
    obj.fun1();
    obj.fun2();
    return 0;
}