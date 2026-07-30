#include <iostream>
#include <string>
using namespace std;

class Person {
    std::string name;
    int age;

public:
    // Main constructor
    Person(std::string n, int a) : name(n), age(a) {
        std::cout << "Person constructor called with name and age\n";
    }

    // Delegating constructor: only name provided, age defaults to 0
    Person(std::string n) : Person(n, 0) {
        std::cout << "Person constructor called with name only\n";
    }

    // Delegating constructor: no parameters, defaults to "Unknown" and 0
    Person() : Person("Unknown") {
        std::cout << "Person default constructor called\n";
    }

    void display() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    Person p1("Alice", 30);
    p1.display();

    Person p2("Bob");
    p2.display();

    Person p3;
    p3.display();

    return 0;
}
