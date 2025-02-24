#include <iostream>
using namespace std;

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };
    
    Node* head;
    Node* tail;
    int size;

public:
    // Constructor
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}
    
    // Destructor
    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    
    // Function to add element at the end
    void push(T data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            //head = newNode;
            //tail = newNode;
            head = tail = newNode;
        } else {
            tail->next = newNode; // the next pointer of the last linked list element points to the newNode
            tail = newNode;
        }
        size++;
    }
    
    // Function to add element at a specific index
    void push(T data, int index) {
        if (index < 0 || index > size) return;
        
        Node* newNode = new Node(data);
        if (index == 0) {
            newNode->next = head;
            head = newNode;
            if (size == 0) tail = newNode;
        } else {
            Node* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next; //current from head to the right position -> find the previous node (current)
            }

            //The newNode should be inserted between current and current->next
            newNode->next = current->next; //(next pointer of newNode points to the next node)
            current->next = newNode; //()
            if (newNode->next == nullptr) tail = newNode;
        }
        size++;
    }
    
    // Function to get element at a specific index
    T get(int index) {
        if (index < 0 || index >= size) return -1;
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }
    
    // Function to delete last element
    void pop() {
        if (!head) return;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
        }
        size--;
    }
    
    // Function to get size of the linked list
    int getSize() { return size; }
    
    // Function to print linked list elements
    void print() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// Driver code
int main() {
    LinkedList<int> list;
    list.push(10);
    list.push(20);
    list.push(30);
    list.push(40);
    list.push(50);
    
    cout << "Linked List size: " << list.getSize() << endl;
    cout << "Linked List elements: ";
    list.print();
    
    list.push(100, 2);
    cout << "\nAfter inserting 100 at index 2:" << endl;
    list.print();
    
    cout << "Element at index 2: " << list.get(2) << endl;
    
    list.pop();
    cout << "\nAfter deleting last element:" << endl;
    list.print();
    cout << "Linked List size: " << list.getSize() << endl;
    
    return 0;
}
