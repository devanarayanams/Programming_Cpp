#include <iostream>
#include <string>
using namespace std;

class Device {
public:
    string name; // Add a member variable to Device

    // Overloaded insertion operator for printing Device objects
    friend ostream& operator<<(ostream& os, const Device& device) {
        os << device.name;
        return os;
    }
};

// Template class for Vector
template<typename T>
class Vector {
private:
    T* items;
    int size;
    int capacity;

public:
    // Constructor to initialize the vector with a specified initial size
    Vector(int initialSize) : items(new T[initialSize]), size(0), capacity(initialSize) {}

    // Destructor to release memory
    ~Vector() {
        delete[] items;
    }

    // Method to add an element to the end of the vector
    void push_back(const T& item) {
        // If capacity is not enough, resize the array
        if (size >= capacity) {
            // Double the capacity
            capacity *= 2;

            // Create a new array with the new capacity
            T* newItems = new T[capacity];

            // Copy existing elements to the new array
            for (int i = 0; i < size; ++i) {
                newItems[i] = items[i];
            }

            // Release memory of the old array
            delete[] items;

            // Update items pointer to point to the new array
            items = newItems;
        }

        // Add the new item to the end of the vector
        items[size++] = item;
    }

    // Overloaded subscript operator for accessing elements by index
    T& operator[](int index) {
        return items[index]; // Return a reference to the element at the specified index
    }

    // Overloaded insertion operator for printing Vector objects
    friend ostream& operator<<(ostream& os, const Vector<T>& v) {
        os << "[";                               // Output opening square bracket to start the representation
        for (int i = 0; i < v.size; ++i) {       // Iterate over each element in the vector
            os << v.items[i];                    // Output the current element to the output stream
            if (i < v.size - 1) {                // Check if the current element is not the last element
                os << ", ";                      // If not the last element, output a comma and a space
            }
        }
        os << "]";                               // Output closing square bracket to end the representation
        return os;
    }
};

int main() {
    // Set the initial size of the integer vector
    int initialSizeInt = 5;

    // Create an integer Vector object with the specified initial size
    Vector<int> vi(initialSizeInt);

    // Add integer elements to the vector
    vi.push_back(10);
    vi.push_back(20);
    vi.push_back(40);
    vi.push_back(60);
    vi.push_back(30);

    // Access and print integer elements using the subscript operator
    int itemInt = vi[2];
    cout << "Element at index 2: " << itemInt << endl; // Output: 40

    // Print the integer vector elements using the insertion operator
    cout << "Integer Vector elements: " << vi << endl; // Output: [10, 20, 40, 60, 30]

    // Set the initial size of the string vector
    int initialSizeStr = 3;

    // Create a string Vector object with the specified initial size
    Vector<string> vs(initialSizeStr);

    // Add string elements to the vector
    vs.push_back("A10");
    vs.push_back("A20");
    vs.push_back("A30");

    // Print the string vector elements using the insertion operator
    cout << "String Vector elements: " << vs << endl; // Output: [A10, A20, A30]

    // Create a Device Vector object with the specified initial size
    Vector<Device> vd(initialSizeStr);

    // Add Device elements to the vector
    Device obj1;
    Device obj2;
    obj1.name = "D1";
    obj2.name = "D2";

    vd.push_back(obj1);
    vd.push_back(obj2);

    // Print the Device vector elements using the insertion operator
    cout << "Device Vector elements: " << vd << endl; // Output: [D1, D2]

    return 0;
}
