#include <iostream>
#include <string>
using namespace std;

class DynamicArray {
private:
    int size, capacity;
    string* array;

    // Helper function to resize the array when capacity is full
    void resize() {
        // Double the capacity
        capacity *= 2;
        string* newArray = new string[capacity]; // Create a new array with the new capacity

        // Copy the elements from the old array to the new array
        for (int i = 0; i < size; i++) {
            newArray[i] = array[i];
        }

        // Delete the old array and point to the new one
        delete[] array;
        array = newArray;
    }

public:
    // Constructor
    DynamicArray(int initialCapacity = 4) {
        size = 0;
        capacity = initialCapacity;
        array = new string[capacity];
    }

    // Destructor to clean up the allocated memory
    ~DynamicArray() {
        delete[] array;
    }

    // Insert a new element at the specified position
    bool insert(string newElement, int position) {
        if (position < 0 || position > size) {
            return false; // Invalid position
        }

        // If the array is full, resize it
        if (size == capacity) {
            resize();
        }

        // Move elements after the position to the right
        for (int i = size; i > position; i--) {
            array[i] = array[i - 1];
        }

        // Insert the new element at the desired position
        array[position] = newElement;
        size++;
        return true; // Successfully inserted
    }

    // Remove an element from the specified position
    bool remove(int position) {
        if (position < 0 || position >= size) {
            return false; // Invalid position
        }

        // Move elements after the position to the left
        for (int i = position; i < size - 1; i++) {
            array[i] = array[i + 1];
        }

        size--; // Decrease the size
        return true; // Successfully removed
    }

    // Print the current elements of the array
    void printArray() const {
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    DynamicArray arr;

    // Insert elements
    arr.insert("apple", 0);
    arr.insert("banana", 1);
    arr.insert("cherry", 2);
    arr.printArray(); // Expected: apple banana cherry

    // Insert an element at the beginning
    arr.insert("grape", 0);
    arr.printArray(); // Expected: grape apple banana cherry

    // Remove an element
    arr.remove(1);
    arr.printArray(); // Expected: grape banana cherry

    // Try to insert when the array is full (resize should happen)
    arr.insert("orange", 2);
    arr.printArray(); // Expected: grape banana orange cherry

    return 0;
}
