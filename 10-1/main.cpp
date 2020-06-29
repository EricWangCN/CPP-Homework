#include<iostream>
using namespace std;
class Base
{
public:
    virtual void what(){
        cout << "class Base." << endl;
    }
};
class Derived : public Base {
public:
    void what(){
        cout << "class Derived." << endl;
    }
};
int main() {
    try {
        throw Derived();
    }
    catch(Base b)
    {
        b.what();
    }
    try {
        throw Derived();
    }
    catch(Base & b)
    {
        b.what();
    }
    return 0;
}