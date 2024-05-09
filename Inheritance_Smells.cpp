#include <string>
#include <iostream>
using namespace std;

// Base class representing a Laptop
class Laptop {
protected:
    Laptop() {} // Protected constructor to prevent direct instantiation

private:
    string modelname;
    string colour;
    float weight;
    string hostOsType;
    int storageCapacity;
};

// Derived class representing an HPLaptop
class HPLaptop : public Laptop {
    // This class inherits from Laptop but does not add any new functionality or behavior.
};

class ZeLaptop {

};

// Example of a class that is not derived from Laptop
class LenovoLaptop {

};

int main() {
    Laptop* obj; // Declaring a pointer to Laptop, but not instantiating any specific derived class.
    // This might indicate a design smell if there is no clear reason for holding a pointer to the base class without using it.
    // It could lead to confusion and difficulty in understanding the code's intent.
    return 0;
}
