#include <iostream>
using namespace std;

class Base {
public:
    mutable int num;
    string str;
    Base(int n):num(n){}
    void Display() const
    {
        cout<<num<<endl;
        num++;
    }
};


int main() {
    Base b(0);
    b.Display();
    b.Display();
    b.Display();
}
/*
    Usually, const fun doesn't allow to change the non-mutable variable values but here num is as mutable that is why the fun allows.
*/