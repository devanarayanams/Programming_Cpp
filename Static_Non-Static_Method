#include <iostream>
#include <string>
using namespace std;

class MyClass {
private:
    int value;

public:
    // Constructor to initialize value
    MyClass(int val) : value(val) {}

    // Non-static method to get the value
    int getValue() {
        return value;
    }

    // Static method to double a given value
    static int doubleValue(int val) {
        return val * 2;
    }
};

int main() {
    // Create an instance of MyClass
    MyClass obj(5);

    // Access non-static method using object instance
    cout << "Value using non-static method: " << obj.getValue() << endl;

    // Access static method using class name
    cout << "Doubled value using static method: " << MyClass::doubleValue(5) << endl;

    return 0;
}
