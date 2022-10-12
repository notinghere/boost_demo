//
// Created by evan on 9/26/22.
//

#include <iostream>
#include "Class1.h"

Class1::Class1() {}

Class1::~Class1() {

}

int Class1::getParam1() const {
    return param1;
}

void Class1::Print() {

    std::cout << "hello ,i am Class1\n";
}

int Class1::getParam2() {
    return 0;
}

bool Class1::operator==(const Class1 &rhs) const {
    return param1 == rhs.param1;
}

bool Class1::operator!=(const Class1 &rhs) const {
    return !(rhs == *this);
}

bool Class1::operator<(const Class1 &rhs) const {


    return param1 < rhs.param1;
}

bool Class1::operator>(const Class1 &rhs) const {


    return rhs < *this;
}

bool Class1::operator<=(const Class1 &rhs) const {
    return !(rhs < *this);
}

bool Class1::operator>=(const Class1 &rhs) const {
    return !(*this < rhs);
}
