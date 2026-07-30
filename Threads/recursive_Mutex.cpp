#include<iostream>
#include<thread>
#include<mutex> 

using namespace std;

recursive_mutex mtx;
int counter = 0;
void Parse(char ch,int count)
{
    if(count<=0)
    {
        return;
    }
    else
    {
        
        mtx.lock();
        cout<<ch<<" "<<++counter<<endl;
        Parse(ch,--count);        
        mtx.unlock();

        
    }
}
void Parse1(char ch,int count)
{
    for(int i=0;i<10;++i)
    {
        mtx.lock();
        cout<<ch<<" "<<++counter<<endl;
        mtx.unlock();
    }
}
int main()
{
    thread t1(Parse1,'0',10);
    thread t2(Parse1,'1',10);
    

    t1.join();
    t2.join();
     
}