#include <iostream>
#include <string>
using namespace std;

// Sample class A
class A {
public:
    A() {
        cout << "A Instantiated" << endl;
    }
    ~A() {
        cout << "A Destructed" << endl;
    }

    // Dummy method for demonstration
    void operation() const {
        cout << "Operation Called" << endl;
    }
};

// Template class for smart pointer
template <typename T>
class SmartPointer {
    T* ptr;

public:
    // Constructor taking a raw pointer
    SmartPointer(T* ptrRef) : ptr(ptrRef) {}

    // Destructor to release memory
    ~SmartPointer() {
        delete ptr;
    }

    // Overloaded arrow operator to access the methods of the pointed object
    T* operator->() const {
        return ptr;
    }
};

// Function to instantiate and use the smart pointer
void instantiate() {
    SmartPointer<A> smartPtr(new A());
    smartPtr->operation(); // Call the operation() method of class A
}

int main() {
    instantiate();
    return 0;
}
