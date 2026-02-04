#include<iostream>
using namespace std;

//static int count=20;
class Strategy{

    public:    
    int id;
    static void fun(){
        static int count = 10; //ignored the re-initialization
        cout<<count<<endl;
        count++;
    }
    void fun2(){
        cout<<count<<endl; 
    }
    //cout<<count<<endl;
};

int main(){

    Strategy::fun();
    Strategy::fun();
    Strategy::fun();

    Strategy obj1;
    obj1.fun2();
    
}
