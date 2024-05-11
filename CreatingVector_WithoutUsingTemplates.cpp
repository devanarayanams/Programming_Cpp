#include <iostream>
#include <string>
using namespace std;

class IntVector {
private:
    int* items;
    int size;
    int capacity;

public:
    IntVector(int initialSize) : items(new int[initialSize]), size(0), capacity(initialSize) {}
    // IntVector() : items(nullptr), size(0), capacity(0) {}
    // Destructor to release memory
    ~IntVector() {
        delete[] items;
    }


    // Method to add an element to the end of the vector
    void push_back(int item) {
        // If capacity is not enough, resize the array
        if (size >= capacity) {
            // check if capacity is 0, then 1 or else Double the capacity
            if (capacity == 0) {
                capacity = 1;
            }
            else {
                capacity *= 2;
            }

            // Create a new array with the new capacity
            int* newItems = new int[capacity];

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
    int& operator[](int index) {
        return items[index]; // Return a reference to the element at the specified index
    }


    // Overloaded insertion operator for printing IntVector objects
    friend ostream& operator<<(ostream& os, const IntVector& v) {
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
    // Set the initial size of the vector
    int initialSize = 5;

    // Create an IntVector object with the specified initial size
    IntVector v(initialSize);

    // Add elements to the vector
    v.push_back(10);
    v.push_back(20);
    v.push_back(40);
    v.push_back(60);
    v.push_back(30);

    // Access and print elements using the subscript operator
    int item = v[2];
    cout << "Element at index 2: " << item << endl; // Output: 40

    // Print the vector elements using the insertion operator
    cout << "Vector elements: " << v << endl; // Output: [10, 20, 40, 60, 30]

    return 0;
}
