#include <iostream>

class Car {
private:
    std::string model;
    int speed;

public:
    Car(std::string m, int s) : model(m), speed(s) {}

    void accelerate(int increase) {
        this->speed += increase;  // this có kiểu Car*
    }

    void display() const {  // Hàm const, this có kiểu const Car*
        std::cout << "Model: " << this->model << ", Speed: " << this->speed << " km/h\n";
    }
};

int main() {
    Car car1("BMW", 70); // car1 là hằng số

    car1.accelerate(10); // Lỗi: Không thể gọi hàm không const trên đối tượng const
    car1.display(); // Hợp lệ vì display() là hàm const

    return 0;
}