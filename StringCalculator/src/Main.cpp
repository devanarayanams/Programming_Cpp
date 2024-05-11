#include <iostream>
#include "StringCalculator.h"
using namespace std;

int main() {
    StringCalculator calculator;
    string input;
    cout << "Enter numbers separated by commas: ";
    getline(cin, input);

    try {
        int result = calculator.add(input);
        cout << "Sum of numbers: " << result << endl;
    } catch (const std::exception &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
