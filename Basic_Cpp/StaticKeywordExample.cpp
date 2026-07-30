#include<iostream>
using namespace std;

class Strategy{
    public:

    static string name;
    static const int orderCount=100;    
    Strategy(int count){
        
    }
    void display(){
        cout<<name<<orderCount<<endl;
    }
    static void Execute(){
        
        cout<<"Executing strategy with order count: "<<orderCount<<endl;
    }
};

string Strategy::name="Order Count: ";

int main()
{
    Strategy obj1(50);
    obj1.display();
    obj1.Execute();
    obj1.display();

}