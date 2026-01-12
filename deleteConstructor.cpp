#include<iostream>
using namespace std;

class Strategy{
    
    public:
    Strategy(int d){
        data = d;
    }
    void display(){
        // Just a sample method to use 'data'
        std::cout << "Data: " << data << std::endl;
    }
    //delete Strategy(); // Delete default constructor
    private:
    int data;



};

int main(){

    Strategy s(10);
    // s.data = 20; // Error: 'data' is private within this context

    s.display();
    

}