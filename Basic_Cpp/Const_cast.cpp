#include <iostream>
using namespace std;

void fun(int* ptr,int num=20)
{
    cout<<num+(*ptr)<<endl;
}
int main() {
    
    const int num = 10;
    const int* ptr = &num;
    cout<<num<<","<<*ptr<<endl;
    
    int* num1 = const_cast<int*>(ptr);
    *num1 = 20; //undefined behaviour means we shouldn't do this.
    cout<<num<<","<<*num1<<endl;
    
    
    fun(const_cast<int*> (ptr));
    return 0;
    
}

/*
    The use of const_cast is to change the value of const data type pointer's value and to pass it to the other function first make sure to cast it.
*/