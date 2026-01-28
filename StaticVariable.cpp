#include<iostream>
using namespace std;

static int y=0;
class Strategy{

    public:    

    void fun();
    void fun2(){
        cout<<y<<endl;
        y++;
    }
    
};
void Strategy::fun(){

    static int count = 0; //ignored the re-initialization
    cout<<count<<endl;
    count++;


}

int main(){

    Strategy obj;
    obj.fun();
    obj.fun();
    obj.fun();

    Strategy obj2,obj3,obj4;
    obj2.fun2();
    obj3.fun2();
    obj4.fun2();
    
}
