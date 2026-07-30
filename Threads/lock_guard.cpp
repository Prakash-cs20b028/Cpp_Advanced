#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

int counter = 0;
mutex mtx;
void FetchData()
{    
    for(int i=0;i<10;i++)
    {
        lock_guard<mutex> lock(mtx);
        ++counter;
        cout<<this_thread::get_id()<<" "<<counter<<endl;
    }
}
int main()
{
    thread t1(FetchData);
    thread t2(FetchData);

    t1.join();
    t2.join();
}