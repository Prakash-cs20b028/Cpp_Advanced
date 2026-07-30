#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

mutex mtx;
bool visitFlag = false;

//Normal Unique Lock Example
void VisitTemple(const char* ch)
{
    unique_lock<mutex> lock(mtx);

    visitFlag = true;

    if(visitFlag)
    {
        cout << ch << " visits the temple." << endl;
    }
    
    lock.unlock();
    
    
}
// Defer Lock Example
void VisitTempleDefer(const char* ch)
{
    unique_lock<mutex> lock(mtx, defer_lock);

    visitFlag = true;

    if(visitFlag)
    {
        cout << ch << " visits the temple." << endl;
    }
    lock.lock();
    lock.unlock();
}

// Try Lock Example
void VisitTempleTryLock(const char* ch)
{
    unique_lock<mutex> lock(mtx, try_to_lock);

    visitFlag = true;

    if(visitFlag)
    {
        cout << ch << " visits the temple." << endl;
    }
    
}

//Adopt Lock Example
void VisitTempleAdopt(const char* ch)
{
    mtx.lock();
    unique_lock<mutex> lock(mtx, adopt_lock);

    visitFlag = true;

    if(visitFlag)
    {
        cout << ch << " visits the temple." << endl;
    }
    lock.unlock();
}
int main()
{
    // thread t1(VisitTemple,"T1");
    // thread t2(VisitTemple, "T2");

    // thread t1(VisitTempleDefer,"T1");
    // thread t2(VisitTempleDefer, "T2");

    // thread t1(VisitTempleTryLock,"T1");
    // thread t2(VisitTempleTryLock, "T2");

    thread t1(VisitTempleAdopt,"T1");
    thread t2(VisitTempleAdopt, "T2");

    t1.join();
    t2.join();
}