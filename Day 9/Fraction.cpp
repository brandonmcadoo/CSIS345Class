#include "Fraction.h"

Fraction Fraction::operator ^ (int power){
    int newNumerator = 1;
    int newDenominator = 1;
    if(power > 0){
        for(int i = 1; i < power; i++){
            newNumerator *= numerator;
            newDenominator *= denominator;
        }
    }
    Fraction retval(newNumerator, newDenominator);
    return retval;
}