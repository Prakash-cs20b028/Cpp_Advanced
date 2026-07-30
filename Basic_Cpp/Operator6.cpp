#include <iostream>
using namespace std;

class MyClass {
public:
    int a;
    MyClass(int n)
    {
        a = n;
    }
    bool operator<=(MyClass obj2)
    {
        return a<=obj2.a;
    }
};


int main() {
    MyClass obj1(10);
    MyClass obj2(10);
    
    cout<<(obj1<=obj2);
    
    
}
