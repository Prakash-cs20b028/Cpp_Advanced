#include<iostream>
#include<chrono>

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
    cout<<even<<endl;
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
    cout<<odd<<endl;
}
int main()
{
    long long start=1,end=123453434;

    auto start_time = high_resolution_clock::now();

    FindEven(start,end);
    FindOdd(start,end);

    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end_time - start_time);

    cout<<duration.count()<<" Milli Seconds"<<endl;

    
}
