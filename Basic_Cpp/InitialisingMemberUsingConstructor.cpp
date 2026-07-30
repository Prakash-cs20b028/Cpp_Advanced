#include<iostream>
using namespace std;

class Car{
    private:
    string brand;
    const int year;

    public:
    Car(string b, int y) : brand(b), year(y) {}; //list initialization syntax
    // Car(string str,int yr){ //const, reference variable not allowed.
    //     brand = str;
    //     year = yr;
    // }
    void displayInfo(){
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};
int main(){

    Car myCar("Toyota", 2020);
    myCar.displayInfo();
    return 0;

}

/*
Benefit of using member initializer list:
1. It is the only way to initialize const and reference members.
2. It can lead to better performance by avoiding unnecessary default construction and assignment.
3. It allows for initialization of base class members in derived classes.
*/