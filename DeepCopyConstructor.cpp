#include <iostream>
using namespace std;

class Bike{
    public:
    double price;
    
    Bike(double p)
    {
        price=p;
        cout<<"Bike Constructor Called with price "<<price<<endl;
    }
};
class Car{
    public:
    double price;
    string color;
    Bike* bike;
    Car(double p,string c)
    {
        price=p;
        color=c;
        bike=new Bike(p/10);
    }
    // Deep Copy Constructor
    Car(const Car &X)
    {
        price=X.price;
        color=X.color;
        //bike=new Bike(); // Allocating new memory for bike
    }
    void display()
    {
        cout<<"Car Price: "<<price<<", Color: "<<color<<endl;
        cout<<"Bike Address: "<<bike<<endl;
    }
};
int main()
{
    Car* car1 = new Car(100000,"Red");
    car1->display();
    
    Car* car2 = new Car(*car1);  // ← this would call it

    delete car1;
    car2->display();
}