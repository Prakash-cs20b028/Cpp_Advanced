#include<iostream>
#include<thread>
#include<future>

using namespace std;

void fun(promise<int>&&p, long start,long end)
{
    int sum=0;
    for(long i=start;i<=end;i++)
    {
        if(i%2 !=0)
        sum+=i;
    }
    p.set_value(sum);
}
int main()
{
    long start=0,end=1000;
    promise<int>p;
    future<int>f=p.get_future();

    thread t1(fun,move(p),start,end);
    t1.join();

    cout<<f.get()<<endl;
}