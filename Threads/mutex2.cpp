#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

int counter = 0;
mutex m;
void Increment()
{
    for(int i=0; i<100; i++)
    {
        m.lock();
        //critical section starts
        counter++;
        //critical section ends
        m.unlock();
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
When we use locks, which means one thread will execute and rest of them will be waiting. 
The case where we don't use lock concept, then in that case we can have a race condition where
multiple threads are trying to access the same resource at the same time and consequently
the value of the resource will be unpredictable or wrong. 
*/