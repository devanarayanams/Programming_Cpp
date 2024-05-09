#include <iostream>

// Parent class
class Parent {
private:
    int q; // Private member variable

public:
    // Parameterized constructor for Parent class
    Parent(int qArg) : q(qArg) {} // Initializes q with the value passed as argument
};

// Child class inheriting from Parent class
class Child : public Parent {
private:
    int x; // Private member variable

public:
    // Default constructor for Child class
    Child() : Parent(10) {} // Calls the parameterized constructor of Parent with value 10

    // Parameterized constructor for Child class
    Child(int xArg) : Parent(xArg) {} // Calls the parameterized constructor of Parent with the value passed as argument
};

int main() {
    // Create a Child object using default constructor
    Child child1;
    
    // Create a Child object using parameterized constructor
    Child child2(20);
    
    return 0;
}
