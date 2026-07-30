#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() { cout << "Base class" << endl; }
    virtual ~Base() {} // Make it polymorphic
};

class Derived1 : public Base {
public:
    void show() override { cout << "Derived1 class" << endl; }
    void derivedFunction() { cout << "Function of Derived1" << endl; }
};
class Derived2 : public Base {
public:
    void show() override { cout << "Derived2 class" << endl; }
    void derivedFunction() { cout << "Function of Derived2" << endl; }
};
int main() {
    
    Base* b1 = new Derived1(); //upcasting 
    //b1->derivedFunction();
    b1->show();
    Derived1* d1 = dynamic_cast<Derived1*>(b1);
    if(d1 == nullptr)
    {
        cout<<"NULL"<<endl;
    }
    d1->show();
    d1->derivedFunction();
    
    Derived2* d2 = dynamic_cast<Derived2*>(b1);
    if(d2 == nullptr)
    {
        cout<<"NULL"<<endl;
    }
    //reference-> 
    try
    {
         Derived1 d4;
         Base &b2 = d4;
         Derived1 &d3 = dynamic_cast<Derived1&>(b2);
         d3.show();
    }
    catch(bad_cast& e)
    {
        cout<<e.what()<<endl;
    }
    
    return 0;
}
/*
	Compulsory, need to have atleast one virtual fun in the base class.
    upcasting is natural but in order to use downcast, we use dynamic_cast.
    Once we have created a pointer of base and referring to the child then dynamic_cast is only possible for that pointer, that is, we can't dynamic_cast to the other child.
*/