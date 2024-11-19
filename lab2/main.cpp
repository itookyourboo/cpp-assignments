#include <iostream>
#include <vector>
#include <list>
#include "MyNumber.hpp"


void processVector(std::vector<MyNumber>& vec) {
    for (auto& num : vec) {
        num.display();
    }
}


MyNumber createMyNumber(int val, const std::string& str) {
    MyNumber num(val, str);
    return num;
}

int main() {
    std::cout << "Creating static object" << std::endl;
    static MyNumber num_1{-1, "minus -1"};
    num_1.display();

    std::cout << "Creating non-static object" << std::endl;
    MyNumber num0;
    num0.display();

    MyNumber num1(1, "one");
    num1.display();

    MyNumber* num2 = new MyNumber(2, "two");
    num2->display();

    std::vector<MyNumber> numVector;
    numVector.emplace_back(3, "three");
    numVector.emplace_back(4, "four");
    processVector(numVector);

    MyNumber num3 = createMyNumber(5, "five");
    num3.display();

    std::list<MyNumber> numList;
    numList.emplace_back(6, "sex");
    numList.emplace_back(7, "seven");
    for (auto& num : numList) {
        num.display();
    }

    delete num2;

    return 0;
}