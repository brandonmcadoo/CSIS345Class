#include <iostream>

int main(){
    Fraction f;
    Fraction* fptr;

    fptr = &f;
    //      ---------------            ---------------
    //      |             |            |      0      |
    // fptr |          ----------->  f |             |
    //      |             |            |      1      |
    //      ---------------            ---------------
    int num = (*fptr).numerator;




    Fraction2 f2;
    int num2 = *(f2.numerator);

    return 0;
}

class Fraction{
    public:
    int numerator = 0;
    int denominator = 1;
};
//   ---------------
//   |      0      |
// f |             |
//   |      1      |
//   ---------------



class Fraction2{
    public:
    int* numerator;
    int* denominator;
};
//   ---------------
//   |  numerator  -------> [  0  ]
// f |             |
//   | denominator -------> [  1  ]
//   ---------------