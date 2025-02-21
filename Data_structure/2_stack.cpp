#include <iostream>
using namespace std;

template <typename T>
class stackClass {
private:
    T* arr;         // Pointer to store elements
    int capacity;   // Total capacity of stack
    int topIndex;   // Index of the top element

public:
    // Constructor: initialize with capacity 1
    stackClass() {
        arr = new T[1];
        capacity = 1;
        topIndex = -1; // Empty stack
    }

    // Destructor: release allocated memory
    ~stackClass() {
        delete[] arr;
    }

    // Push an element onto the stack
    void push(T data) {
        // Resize if stack is full
        if (topIndex + 1 == capacity) {
            T* temp = new T[2 * capacity];

            // Copy old elements
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }

            // Delete old memory
            delete[] arr;
            arr = temp;
            capacity *= 2;
        }

        // Add element on top
        arr[++topIndex] = data;
    }

    // Pop (remove top element)
    void pop() {
        if (topIndex == -1) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        topIndex--;
    }

    // Peek the top element
    T top() {
        if (topIndex == -1) {
            cout << "Stack is empty!" << endl;
            return -1; // Returning -1 for invalid cases (handle properly for non-int types)
        }
        return arr[topIndex];
    }

    // Get current size of the stack
    int size() {
        return topIndex + 1;
    }

    // Get current capacity of the stack
    int getCapacity() {
        return capacity;
    }

    // Print stack elements
    void print() {
        if (topIndex == -1) {
            cout << "Stack is empty!" << endl;
            return;
        }
        for (int i = topIndex; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Driver Code
int main() {
    stackClass<int> s;

    // Push elements
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << "Stack elements: ";
    s.print();

    cout << "Top element: " << s.top() << endl;

    s.pop();
    cout << "Stack after pop: ";
    s.print();

    cout << "Stack size: " << s.size() << endl;
    cout << "Stack capacity: " << s.getCapacity() << endl;

    return 0;
}
