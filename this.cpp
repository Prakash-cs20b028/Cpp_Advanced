#include<iostream>
using namespace std;

class Strategy{

    public:
    int order_num;
    int order_id;
    string name;

    void fun(){

        this->order_num = 10;
        this->name = "Strategy Pattern";
    }
    void fun2(){
        this->order_id = 20;
        this->name = "Another Strategy";
    }
};

int main(){
    Strategy obj;
    obj.fun();
    cout << "Order Number: " << obj.order_id << endl;
    Strategy obj2;
    obj2.fun2();
    cout << "Order Name: " << obj2.name << endl;



}

//Those items will be executed in the function which is called by the object.
//This is similar to obj.