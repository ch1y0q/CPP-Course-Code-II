#pragma once
#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
class Rational
{
public:
	Rational(int, int);
	Rational add(Rational);
	Rational minus(Rational);
	Rational multiply(Rational);
	Rational divide(Rational);
	void print() const;
	void printf() const;

private:
	int numerator;
	int dominator;
};
#endif