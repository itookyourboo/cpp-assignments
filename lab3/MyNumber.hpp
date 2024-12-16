#ifndef MYNUMBER_HPP
#define MYNUMBER_HPP

#include <iostream>
#include <string>
#include <random>
#include <vector>
#include <algorithm>
#include <list>

class MyNumber {
private:
    int value = 0; 
    std::string stringValue;

public:
    MyNumber() = default;    
    MyNumber(int val, const std::string& str) : value(val), stringValue(str) {}
    int getValue() const { return value; }
    const std::string& getStringValue() const { return stringValue; }
    bool operator<(const MyNumber& other) const {
        return value < other.value;
    }
};


#endif // MYNUMBER_HPP