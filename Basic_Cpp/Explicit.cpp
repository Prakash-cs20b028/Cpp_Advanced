// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Explicit
{
   public:
   int x;
   explicit Explicit(int n):x(n){};
   
};
int main() {
    
    Explicit ex = 10;
    return 0;
}

/*
	The use of the explicit keyword is to stop the implicit conversion. 
	For example, in the above example, I have created an object and initialising with 10 which works in general. But
	here it won't because of the explicit keyword. 
*/