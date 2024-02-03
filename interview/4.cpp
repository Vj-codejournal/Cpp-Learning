#include <iostream>

class MyNumber {
private:
    int value;

public:
    MyNumber(int val) : value(val) {}

    MyNumber operator*(const MyNumber& other) {
        return MyNumber(value * other.value);
    }

    MyNumber operator+(const MyNumber& other) {
        return MyNumber(value + other.value);
    }

    MyNumber operator-(const MyNumber& other) {
        return MyNumber(value - other.value);
    }

    void display() {
        std::cout << "Value: " << value << std::endl;
    }
};

int main() {
    MyNumber obj1(5);
    MyNumber obj2(2);
    MyNumber obj3(3);
    MyNumber obj4(1);

    MyNumber result = obj1 + obj2 * obj3 - obj4;

    std::cout << "Result of the expression: ";
    result.display();

    return 0;
}