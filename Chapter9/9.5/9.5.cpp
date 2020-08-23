#include <iostream>
#include "Complex.h"

using namespace std;

Complex::Complex(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {};

void Complex::add(Complex c)
{
	real += c.real;
	imaginary += c.imaginary;
}

void Complex::minus(Complex c)
{
	real -= c.real;
	imaginary -= c.imaginary;
}

void Complex::print()
{
	cout << real << (imaginary>0?" + ":" ") << imaginary << "i" << endl;
}

int main()
{
	Complex c1, c2(1.14514, 2.14514);
	//c1.add(c2);
	c1.print();
	c1.minus(c2);
	c1.print();
	return 0;
}