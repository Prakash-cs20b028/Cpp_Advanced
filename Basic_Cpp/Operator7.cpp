#include<iostream>
using namespace std;

class Base {
public:
    int base;
    Base(int x){
        base = x;
    }
    int operator()(int x)
    {
        return base+x;
    }
    
};

int main() {
    Base b(10);
    cout<<b(20);
}
