#ifndef MYNUMBER_HPP
#define MYNUMBER_HPP

#include <iostream>
#include <string>

class MyNumber {
private:
    int value; 
    std::string stringValue;

public:
    MyNumber();
    MyNumber(int val, const std::string& str);
    MyNumber(const MyNumber& other);
    MyNumber(MyNumber&& other) noexcept;

    ~MyNumber();

    MyNumber& operator=(const MyNumber& other);
    MyNumber& operator=(MyNumber&& other) noexcept;

    // Метод для вывода значения
    void display();
};

#endif // MYNUMBER_HPP