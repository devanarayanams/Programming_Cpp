#include <iostream>
#include <string>

using namespace std;

// Custom KeyValuePair class
template <typename K, typename V>
class KeyValuePair {
public:
    K key;
    V value;
};

// Template class for Dictionary
template<typename K, typename V>
class Dictionary {
private:
    KeyValuePair<K, V>* keyValuePairs;
    int capacity;
    int size;

public:
    // Constructor to initialize the dictionary with a specified initial capacity
    Dictionary(int initialCapacity) : capacity(initialCapacity), size(0) {
        keyValuePairs = new KeyValuePair<K, V>[capacity];
    }

    // Destructor to release memory
    ~Dictionary() {
        delete[] keyValuePairs;
    }

    // Method to add a key-value pair to the dictionary
    void add(K key, V value) {
        if (size >= capacity) {
            // If capacity is not enough, double the capacity
            capacity *= 2;
            // Create a new array with the new capacity
            KeyValuePair<K, V>* newKeyValuePairs = new KeyValuePair<K, V>[capacity];
            // Copy existing key-value pairs to the new array
            for (int i = 0; i < size; ++i) {
                newKeyValuePairs[i] = keyValuePairs[i];
            }
            // Release memory of the old array
            delete[] keyValuePairs;
            // Update keyValuePairs pointer to point to the new array
            keyValuePairs = newKeyValuePairs;
        }
        // Add the new key-value pair to the dictionary
        keyValuePairs[size].key = key;
        keyValuePairs[size].value = value;
        size++;
    }

    // Overloaded subscript operator for accessing values by key
    V& operator[] (K key) {
        for (int i = 0; i < size; ++i) {
            if (keyValuePairs[i].key == key) {
                return keyValuePairs[i].value;
            }
        }
        // If key is not found, add a new key-value pair with a default value
        add(key, V());
        return keyValuePairs[size - 1].value;
    }
};

int main() {
    Dictionary<string, string> stringMap(10); // Initial capacity set to 10
    stringMap.add("Blr", "B");
    stringMap.add("Klr", "K");
    string value = stringMap["Blr"]; // output should be B
    cout << value << endl;

    Dictionary<string, int> stringToIntMap(10); // Initial capacity set to 10
    int number = stringToIntMap["One"] = 1; // output should be 1
    cout << number << endl;

    return 0;
}
