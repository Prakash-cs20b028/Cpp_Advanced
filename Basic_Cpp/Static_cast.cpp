#include <iostream>
using namespace std;

class Shape
{
    int x;
    public:
    Shape(int x)
    {
        this->x = x;
        cout<<"Constructor is called: "<<x<<endl;
    }
    operator string(){
        return to_string(x);
    }
};
class Circle: public Shape
{
    public:
    int y;
    Circle(int x):Shape(x){
        y = x;
    }
};
int main() {
    
    //void pointer concept->
    int a = 10;
    void* p = static_cast<void*>(&a);
    cout<<*(int*)p<<endl;
    
    /*
    //Downcast->
    
    Circle c3(40);
    Circle c4(50);
    Shape* s1 = static_cast<Shape*>(&c3); //upcast
    Shape* s2 = static_cast<Shape*>(&c4);
    Circle *c5 = static_cast<Circle*>(s2); //downcast is also allowed with the diff child which might give some error in the future.
    Circle *c6 = static_cast<Circle*>(s1);
    
    
    //private vs public->
    
    Circle c2(30);
    Shape* sh = (Shape*)&c2;
    Shape* sh2 = static_cast<Shape*>(&c2);
    
    
    //char* to int* allowed in c but not in cpp->
    
    char *ch = new char();
    int *p = (int*)ch;
    *p = 5;
    cout<<*p;
    int *p2 = static_cast<int*>(ch); Not allowed in cpp
    
    //conversion operator and conversion constructor->
    
    Circle c1(10);
    string str1 = c1;
    c1 = 20;
    string str2 = static_cast<string>(c1);
    c1 = static_cast<int>(30);
    cout<<str2<<endl;
    
    //Normal concept->
    
    float f=10.25;
    int a;
    //a = f;
    a = static_cast<int>(f);
    cout<<"Float: "<<f<<endl<<"Int: "<<a<<endl;
    
    */
    
    
}