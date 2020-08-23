#include <iostream>
#include <iomanip>
#include "Rational.h"
using namespace std;

// greatest common divisor
int gcd(int a, int b)
{
	if (b == 0)return a;
	return gcd(b, a % b);
}

// least common multiple
int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

Rational::Rational(int n, int d)
{
	int g = gcd(n, d);
	n /= g;
	d /= g;
	numerator = n;
	dominator = d;
}

Rational Rational::add(Rational b)
{
	int n = this->numerator * b.dominator / gcd(this->dominator, b.dominator)
		+ b.numerator * this->dominator / gcd(this->dominator, b.dominator);
	int d = lcm(this->dominator, b.dominator);
	int g = gcd(n, d);
	n /= g;
	d /= g;
	this->numerator = n;
	this->dominator = d;
	return Rational(n, d);
}

Rational Rational::minus(Rational b)
{
	int n = this->numerator * b.dominator / gcd(this->dominator, b.dominator)
		- b.numerator * this->dominator / gcd(this->dominator, b.dominator);
	int d = lcm(this->dominator, b.dominator);
	int g = gcd(n, d);
	n /= g;
	d /= g;
	this->numerator = n;
	this->dominator = d;
	return Rational(n, d);
}

Rational Rational::multiply(Rational b)
{
	int n = this->numerator * b.numerator;
	int d = this->dominator * b.dominator;
	int g = gcd(n, d);
	n /= g;
	d /= g;
	this->numerator = n;
	this->dominator = d;
	return Rational(n, d);
}

Rational Rational::divide(Rational b)
{
	Rational t(b.dominator, b.numerator);
	return multiply(t);
}

void Rational::print() const
{
	cout << numerator << " / " << dominator << endl;
}

void Rational::printf() const
{
	cout << fixed << setprecision(3) << numerator * 1.0 / dominator << endl;
}

int main()
{
	Rational r1(2, 4), r2(3, 6), r3(1, 4), r4(-1, 3);

	r1.printf();
	r1.print();
	r2.add(r3);
	r2.print();
	r1.multiply(r3);
	r1.print();
	r3.divide(r4);
	r3.print();
	return 0;
}