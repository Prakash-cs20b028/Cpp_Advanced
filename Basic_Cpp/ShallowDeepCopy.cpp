// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Circle{
    int* rad;
    public:
        Circle(int r)
        {
            rad = new int(r);
        }
        Circle(const Circle& other)
        {
            //rad = other.rad;  //shallow copy(Only address of the allocated mem copied)
            rad = new int(*other.rad); //deep copy(value copied)
        }
        void Display()
        {
            cout<<"Address: "<<rad<<endl;
            cout<<"Area of circle is: "<<3.14*(*rad)*(*rad)<<endl;
        }
};
int main() {
    // Write C++ code here
    Circle c1(10);
    Circle c2 = c1;
    
    c1.Display();
    c2.Display();
    
    Circle* c3 = new Circle(10);
    Circle* c4 = c3;
    c3->Display();
    c4->Display();
    return 0;
}