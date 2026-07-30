#include<iostream>
#include<mutex>
#include<thread>

using namespace std;

int x = 0;
mutex m;

void AddMoney()
{
    m.lock();
    cout<<"Thread ID: "<<this_thread::get_id()<<endl;
    x++;
    m.unlock();
}
int main()
{
    thread t1(AddMoney);
    thread t2(AddMoney);
    thread t3(AddMoney);
    thread t4(AddMoney);
    
    t4.join();
    t1.join();
    t2.join();
    t3.join();
    
    int x = 1;
    //x++;
    cout<<x++<<endl;
    //cout << y << endl;    
    return 0;
}

/*
If I have a global variable and local variable with the same name then
the local variable will be given preference over the global variable based on the 
scope of the variable. So, in this case local variable will be executed in the main 
function and the global variable will be executed in the AddMoney function.

The use of the mutex is to remove the race condition and get the desired value correctly. 

When we use locks, which means one thread will execute and rest of them will be waiting. 
The case where we don't use lock concept, then in that case we can have a race condition where
multiple threads are trying to access the same resource at the same time and consequently
the value of the resource will be unpredictable or wrong. 
*/