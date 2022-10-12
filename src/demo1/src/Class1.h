//
// Created by evan on 9/26/22.
//

#ifndef TEST1_CLASS1_H
#define TEST1_CLASS1_H


class Class1 {
public:
    Class1();

    virtual ~Class1();

private:
    int param1;
public:
    int getParam1() const;

    void Print();

    int getParam2();

    bool operator==(const Class1 &rhs) const;

    bool operator<(const Class1 &rhs) const;

    bool operator>(const Class1 &rhs) const;

    bool operator<=(const Class1 &rhs) const;

    bool operator>=(const Class1 &rhs) const;

    bool operator!=(const Class1 &rhs) const;
};


#endif //TEST1_CLASS1_H
