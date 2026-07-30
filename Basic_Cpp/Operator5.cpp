#include <iostream>
using namespace std;

class MyClass {
public:
    int a;
    MyClass(int n)
    {
        a = n;
    }
    void Display()
    {
        cout<<"Value of a is: "<<a<<endl;
    }
    void operator=(MyClass obj)
    {
        a = obj.a;
    }
};


int main() {
    MyClass obj1(10);
    obj1.Display();
    
    MyClass obj2 = obj1;  //copy constructor
    obj2.Display();
    
    MyClass obj3(100);
    obj3 = obj1;           //assignment operator
    obj1.Display();
    
    
}
