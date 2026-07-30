#include <iostream>
using namespace std;

void fun(int a = 0, int b = 0) {
    cout << a << b << endl;
}

int main() {
    fun(10); 
    return 0;
}

/*
	Here, compulsory we need to initialize the parameter in the calling function. If not 
	then we need to pass the parameter from the called function. Calling function can have more number
	of parameter but the called function don't.
*/