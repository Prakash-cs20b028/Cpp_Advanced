#include<iostream>
using namespace std;

class Bike{
    string name, model;
    public:
    Bike(string name, string model){
        this->name = name;
        this->model = model;
        cout<<"Bike Constructor called!"<<endl;
    }
};
class Car{
    string id;
    int year;
    
    public:
    Bike* bike;
    Car(string id,int year){
        this->id = id;
        this->year = year;
        bike = new Bike("Yamaha", "2020");
        cout<<"Car Constructor called!"<<endl;
        
    }
    ~Car(){
        delete bike;
        cout<<"Car Destructor called!"<<endl;
    }
    void Display(){
        cout<<"Car ID: "<<id<<", Year: "<<year<<endl;
        cout<<"Bike Address: "<<bike<<endl;
    }
};
int main(){

    Car *car1 = new Car("Audi", 2021);
    car1->Display();
    cout<<car1->bike<<endl;
    Car car2(*car1); // Default copy constructor is called here
    delete car1;
    car2.Display();
    cout<<car2.bike<<endl;
    
    return 0;
}