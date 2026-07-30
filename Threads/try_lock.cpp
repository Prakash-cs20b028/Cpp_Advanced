#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

int counter = 0;
mutex m;
void Increment()
{
    for(int i=0;i<100000;i++)
    {
        if(m.try_lock())
        {
            counter++;
            m.unlock();
        }        
    }
}
int main()
{
    thread t1(Increment);
    thread t2(Increment);

    t1.join();
    t2.join();

    cout<<"Final value of counter: " << counter << endl;
    return 0;
}

/*
The difference between lock and try_lock is that lock will make the threads wait
until it gets executed. But try_lock will not make the threads wait rather the other threads
will be still trying to get the critical section by loosing their iterations. 
*/