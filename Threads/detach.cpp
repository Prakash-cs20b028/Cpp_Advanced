#include<iostream>
#include<thread>
#include<chrono>

using namespace std;
auto fun = [](int n){
    while(n>0)
    {
        cout<<n<<endl;
        n--;
    }
};
int main()
{
    thread t1(fun,5);
    cout<<"Execution commenced"<<endl;
    t1.detach();
    cout<<"Execution completed"<<endl;

    //this_thread::sleep_for(chrono::seconds(1));
    return 0;
}

/*
The use of detach() function is to detach the thread from the main thread.
The main thread will not wait for the detached thread to complete its execution.
If child thread has the capacity to complete its execution before the main function returns
then this is good. But if the child thread is still executing and the main function returns
then the child thread will be terminated.

It is must to add either join() or detach() function to the thread object.
If we don't add any of these functions then the program will terminate with an error.
*/