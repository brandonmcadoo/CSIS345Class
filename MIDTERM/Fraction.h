#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
using std::ostream;

class Fraction {
public:
	int *num;
	int *den;
	Fraction();
	Fraction(int num);
	Fraction(int num, int den);
    Fraction(const Fraction &f);
	void print();
	void add(Fraction &f);
	void lowestTerms();
	~Fraction();
	const Fraction& operator=(const Fraction &f);
	const Fraction& operator+(const Fraction &f);
	const Fraction& operator-(const Fraction &f);
	const Fraction& operator*(const Fraction &f);
	const Fraction& operator/(const Fraction &f);
	friend Fraction operator+(const Fraction& lhs, int rhs);
	friend Fraction operator+(int lhs, const Fraction& rhs);
	const Fraction& operator++();
	const Fraction operator++(int);
	friend ostream& operator<<(ostream& out, const Fraction& f);
    const Fraction operator ^ (int);
};

#endif