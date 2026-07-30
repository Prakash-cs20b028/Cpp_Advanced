#include<iostream>
#include<chrono>
#include<thread>

using namespace std;
using namespace chrono;

void fun(int x)
{
    while(x>0)
    {
        cout<<x<<endl;
        x--;
    }
    //this_thread::sleep_for(chrono::seconds(5));

}
int main()
{
    auto start_time = high_resolution_clock::now();
    
    thread t1(fun,5);
    printf("Hi!\n");
    //t1.join();
    printf("Hello!\n");

    if(t1.joinable())
    {
        t1.join();
    }
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end_time - start_time);
    cout<<duration.count()<<" Milli Seconds"<<endl;
}