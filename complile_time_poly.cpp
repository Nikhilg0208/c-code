#include <bits/stdc++.h>
using namespace std;
class funover
{
public:
    int add(int a, int b)
    {
        return a + b;
    }
    int add(int a, int b, int c)
    {
        return a + b + c;
    }
};
int main()
{
    funover obj;
    cout << obj.add(1, 2) << "\n"; //  complie time decide which function will be called also known as Static Polymorphism.
    cout << obj.add(1, 2, 3) << "\n";
    return 0;
}