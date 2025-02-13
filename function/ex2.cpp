//return type of function in C: all data types except for function and arrays.
//derived data types including: pointer, function, array

#include <iostream>

struct Point {
    int x;
    int y;
};

Point createPoint(int a, int b){
    Point p;
    p.x = a;
    p.y = b;
    return p;
}

void createPoint_reference(Point& p, int a, int b){
    p.x = a;
    p.y = b;
}

int* allocateArray(int size){
    int* arr = new int[size];
    for(int i=0; i < size; i++){
        arr[i] = i + 1;
    }
    return arr;
}


int main(){
    Point p1 = createPoint(0,0);
    std::cout << p1.x << std::endl;
    std::cout << p1.y << std::endl;

    Point p2;
    createPoint_reference(p2, 5, 6);
    std::cout << p2.x << std::endl;
    std::cout << p2.y << std::endl;

    int size = 5;
    int* array = allocateArray(size);
    std::cout << "array elements:" << std::endl;
    for(int i=0; i < size; i++){
        std::cout << array[i] << std::endl;
    }

}