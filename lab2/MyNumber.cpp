#include "MyNumber.hpp"


MyNumber::MyNumber() : value(0), stringValue("") {
    std::cout << "Empty constructor called" << std::endl;
}

MyNumber::MyNumber(int val, const std::string& str) : value(val), stringValue(str) {
    std::cout << "Constructor called for value: " << value << std::endl;
}


MyNumber::MyNumber(const MyNumber& other) : value(other.value), stringValue(other.stringValue) {
    std::cout << "Copy constructor called for value: " << value << std::endl;
}


MyNumber::MyNumber(MyNumber&& other) noexcept : value(other.value), stringValue(std::move(other.stringValue)) {
    std::cout << "Move constructor called for value: " << value << std::endl;
}


MyNumber::~MyNumber() {
    std::cout << "Destructor called for value: " << value << std::endl;
}


MyNumber& MyNumber::operator=(const MyNumber& other) {
    if (this != &other) {
        value = other.value;
        stringValue = other.stringValue;
        std::cout << "Assignment operator (copy) called for value: " << value << std::endl;
    }
    return *this;
}


MyNumber& MyNumber::operator=(MyNumber&& other) noexcept {
    if (this != &other) {
        value = other.value;
        stringValue = std::move(other.stringValue);
        std::cout << "Assignment operator (move) called for value: " << value << std::endl;
    }
    return *this;
}


void MyNumber::display() {
    std::cout << "Value: " << value << ", String Value: " << stringValue << std::endl;
}
