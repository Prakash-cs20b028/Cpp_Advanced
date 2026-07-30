#include<iostream>
#include<chrono>
#include<thread>

using namespace std;
using namespace chrono;

void FindEven(long start,long end)
{
    long even = 0;
    for(long i=start;i<=end;i++)
    {
        if(i%2==0)
        {
            even+=i;
        }
    }
    cout<<"Even is "<<even<<endl;
}
void FindOdd(long start,long end)
{
    long odd = 0;
    for(long i=start;i<=end;i++)
    {
        if(i%2!=0)
        {
            odd+=i;
        }
    }
    cout<<"Odd is "<<odd<<endl;
}
int main()
{
    long long start=1,end=123453434;

    auto start_time = high_resolution_clock::now();

    thread t1(FindEven,start,end);
    thread t2(FindOdd,start,end);    
    
    t1.join();
    cout<<"Hello "<<endl;
    t2.join();

    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end_time - start_time);

    cout<<duration.count()<<" Milli Seconds"<<endl;
    
}
