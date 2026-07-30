#include<iostream>
#include<thread>
using namespace std;

void funpointer(int x)
{
    while(x>0)
    {
        cout<<x<<endl;
        x--;
    }
}
auto lambdafunction =[](int x){
    while(x>0)
    {
        cout<<x<<endl;
        x--;
    }
};
class Base
{
    public:
    void operator()(int x)
    {
        while(x>0)
        {
            cout<<"Operator: "<<x<<endl;
            x--;
        }
    }
    void func(int x)
    {
        while(x>0)
        {
            cout<<"func: "<<x<<endl;
            x--;
        }
    }
    static void staticfunc(int x)
    {
        while(x-->0)
        {
            cout<<"Static func"<<x<<endl;
            //x--;
        }
    }
};
int main()
{
    //function pointer
    //thread t1(funpointer,10);

    //lambda function
    //thread t1(lambdafunction,10);
    // thread t2([](int x){
    //     while(x>0)
    //     {
    //         cout<<x<<endl;
    //         x--;
    //     }
    // },10);
    // t2.join();

    //functor
    thread t3((Base()),10);
    t3.join();

    //non-static method
    // Base b;
    // thread t4(&Base::func,b,10);
    // t4.join();

    //static method
    //thread t5(&Base::staticfunc, 10);
}
