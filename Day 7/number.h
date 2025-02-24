#ifndef NUMBER_H
#define NUMBER_H

#include <iostream>
using std::cout;
using std::endl;

class Number{
    public:
    Number();
    Number(const Number &n);
    const Number& operator=(const Number &n);
    ~Number(); 
    int *number;
};

#endif