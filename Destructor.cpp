#include<iostream>
using namespace std;

class Strategy{
    public:
    int id;
    int *price;
    Strategy(int id):price(new int(id)){};
    ~Strategy(){
        cout<<"Destructor Called for Strategy with id "<<id<<endl;
        delete price;
    }
};
int main(){
    Strategy* s1=new Strategy(101);
    cout<<"Strategy Price: "<<*(s1->price)<<endl;
    s1->~Strategy(); // Manually calling destructor
    delete s1; // Destructor will be called here
    return 0;
}