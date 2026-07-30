#include<iostream>
using namespace std;

class Car{
    string name;
    int model;
    public:
    Car(string name,int model){
        this->name = name;
        this->model = model;
    }  
    Car(const Car &c){ // Not needed as compiler provides a default copy constructor
        name = c.name;
        model = c.model;
        cout<<"Copy Constructor called!"<<endl;
    }
    void Display(){
        cout<<"Car Name: "<<name<<", Model: "<<model<<endl;
    }    
};
int main(){

    Car car1("BMW",2022);
    car1.Display();

    Car car2(car1); // Copy Constructor is called here
    Car car3 = car2; //direct initialization also calls copy constructor
    car2.Display();    

    return 0;
}
