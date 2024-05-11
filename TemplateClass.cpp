#include <iostream>
#include <string>
using namespace std;

// Template class Stack for a generic stack data structure
template <typename T>
class Stack {
    T item[100]; // Array to store elements of type T
public:
    // Function to push an item onto the stack
    void push(T item) {
        // Implementation of push method...
    }

    // Function to pop an item from the stack
    T pop() {
        // Implementation of pop method...
        T temp; // Temporary variable to store the popped item
        return temp; // Placeholder return statement
    }
};

int main() {
    // Instantiate a stack of integers
    Stack<int> intStack;
    
    // Instantiate a stack of strings
    Stack<string> strStack;

    return 0;
}
