#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

mutex m1,m2,m3;
int counter = 0;

void Increment()
{
    for(int i=0;i<50000;++i)
    {
        int res = try_lock(m1,m2,m3);
        if(res == -1)
        {
            ++counter;
            m1.unlock();
            m2.unlock();
            m3.unlock();
        }
        else
        {
            cout<<"Thread "<<this_thread::get_id()<<" failed to acquire lock "<<res<<endl;
        }
    }
}

int main()
{
    thread t1(Increment);
    thread t2(Increment);
    thread t3(Increment);

    t1.join();
    t2.join();
    t3.join();

    cout<<"Final counter value: "<<counter<<endl;
    return 0;
}