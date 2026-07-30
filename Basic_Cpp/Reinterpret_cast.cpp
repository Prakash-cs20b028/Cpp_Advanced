#include <iostream>
using namespace std;

class Pointer{
    public:
      int num;
      char ch;
      bool flag;
      
};
int main() {
    
    Pointer p1;
    cout<<"Size of p1: "<<sizeof(p1)<<endl;
    
    p1.num = 10;p1.ch = 'z';p1.flag = true;
    
    
    int* n = reinterpret_cast<int*>(&p1);
    
    char* ch1 = (char*)(n);
   
    cout << "Address pointed to by n (after casting to char*): " << n << endl;
    cout << "Address pointed to by ch1 (right after cast):    " << (void*)ch1<<endl; 
    ch1++;ch1++;ch1++;ch1++;
    n++;
    cout << "Address pointed to by n (after casting to char*): " << n << ", ch1: "<<(void*)ch1<<endl;
    
    bool* b = reinterpret_cast<bool*>(ch1);
    cout << "Address pointed to by b (right after cast):    " <<b<<endl;
    b++;
    cout<<"Value of b: "<<*b<<endl;
    
    return 0;
}