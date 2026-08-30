#include <iostream>
#include <string>
using namespace std;
// In C++ programming there is no built-in concept of interfaces. In order to create an interface, we need to create an abstract class which is having only pure virtual methods
class GFG // Interfaces are also called pure abstract classes.
{
public:
    virtual string returnString() = 0; // if class only having one pure virtual function called interface.
};

class child : public GFG
{
public:
    string returnString()
    {
        return "GeeksforGeeks";
    }
};
int main()
{
    GFG *ptr;
    child childObj;
    ptr = &childObj;
    cout << ptr->returnString();
    return 0;
}
