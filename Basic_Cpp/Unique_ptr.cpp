#include <memory>
#include <iostream>
using namespace std;

class Car {
public:
    Car() { std::cout << "Car created\n"; }
    ~Car() { std::cout << "Car destroyed\n"; }
    void drive() { std::cout << "Driving...\n"; }
};

int main() {
    unique_ptr<Car> owner = make_unique<Car>();
    owner->drive();
    
    unique_ptr<Car> newOwner = move(owner); //the move is needed otherwise it gives an error.
    return 0;
}
