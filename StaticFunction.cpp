#include<iostream>
using namespace std;

class Strategy{

    public:    
    int id;
    static void fun(){
        int count = 10; //ignored the re-initialization
        cout<<count<<endl;
        count++;
    }
    
};

int main(){

    Strategy::fun();
    Strategy::fun();
    Strategy::fun();
    
}
