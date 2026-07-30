#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>

using namespace std;
using namespace chrono;

mutex m1;
mutex m2;

void thread1()
{
    m1.lock();
    this_thread::sleep_for(chrono::seconds(1));
    m2.lock();
    cout<<"Critical Section for thread1"<<endl;
    m1.unlock();
    m2.unlock();

}
void thread2()
{
    m2.lock();
    this_thread::sleep_for(chrono::seconds(1));
    m1.lock();
    cout<<"Critical Section for thread2"<<endl;
    m2.unlock();
    m1.unlock();
}
int main()
{
    thread t1(thread1);
    thread t2(thread2);

    t1.join();
    t2.join();

    return 0;
}