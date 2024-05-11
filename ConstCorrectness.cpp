#include <iostream>
#include <string>
using namespace std;

// Function f3 takes a reference to a string and modifies it
void f3(string& arg) { // references - l value
    arg = "hello there";
}

// Function f2 takes a pointer to a const string and tries to modify the string, but it's not allowed due to const correctness
void f2(const string* arg) {
    *arg = "Hello"; // Error: Attempting to modify a const string
}

// Function f1 takes a string by value and modifies it, but the modification doesn't affect the original string passed in the main function
void f1(string arg) {
    arg = "hello"; // Modifies the local copy of the string, not the original
}

int main() {
    string data = "hi"; // Declare a string variable
    f1(data); // Call f1 with the string variable
    cout << data << endl; // Output: hi (no change because f1 modifies a local copy)

    f2(&data); // Call f2 with the address of the string variable
    // Error: Attempting to modify a const string

    f3(data); // Call f3 with the string variable
    cout << data << endl; // Output: hello there (data modified by f3)

    return 0;
}
