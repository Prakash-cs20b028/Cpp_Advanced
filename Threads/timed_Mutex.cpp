#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>

using namespace std;
int counter = 0;

timed_mutex mtx;

void Increment()
{
    for(int i=0;i<5;++i)
    {
        auto duration = chrono::seconds(3);
        if(mtx.try_lock_for(duration))
        {
            ++counter;
            chrono::seconds sleep_duration(1);
            this_thread::sleep_for(sleep_duration);
            mtx.unlock();
        }
        else
        {
            printf("Other Thread busy\n");
        }
    }
}
void Increment2()
{
    for(int i=0;i<5;++i)
    {
        auto time = chrono::steady_clock::now()+chrono::seconds(3);
        if(mtx.try_lock_until(time))
        {
            ++counter;
            chrono::seconds sleep_duration(1);
            this_thread::sleep_for(sleep_duration);
            mtx.unlock();
        }
        else
        {
            printf("Other Thread busy\n");
        }
    }
} 
int main()
{
    thread t1(Increment2);
    thread t2(Increment2);
    thread t3(Increment2);

    t1.join();
    t2.join();
    t3.join();

    cout<<"Final counter value: "<<counter<<endl;
}