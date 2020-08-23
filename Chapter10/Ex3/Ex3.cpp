#include <iostream>
using std::cout;
using std::endl;
#include "RationalNumber.h"

int gcd(int a, int b)
{
	if (b == 0)return a;
	return gcd(b, a % b);
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

RationalNumber::RationalNumber(int n, int d)
{
	if (d == 0) {
		std::cout << "0 is not a valid value for denominator. Using 1 instead." << std::endl;
		d = 1;
	}
	int sign = (n * d < 0) ? -1 : 1;
	n = abs(n);
	d = abs(d);
	int g = gcd(n, d);
	n /= g;
	d /= g;
	numerator = n * sign;
	denominator = d;
}

bool RationalNumber::operator>(const RationalNumber& b) const
{
	return numerator * b.denominator > b.numerator * denominator;
}
bool RationalNumber::operator<(const RationalNumber& b) const
{
	return (b > * this);
}
bool RationalNumber::operator>=(const RationalNumber& b) const
{
	return !(*this < b);
}
bool RationalNumber::operator<=(const RationalNumber& b) const
{
	return !(*this > b);
}
bool RationalNumber::operator==(const RationalNumber& b) const
{
	return (numerator == b.numerator && denominator == b.denominator);
}
bool RationalNumber::operator!=(const RationalNumber& b) const
{
	return !(*this == b);
}

void RationalNumber::printRational() const
{
	if (denominator != 1)
		cout << numerator << " / " << denominator;
	else
		cout << numerator;
}

void RationalNumber::reduction()
{
	int g = gcd(numerator, denominator);
	numerator /= g;
	denominator /= g;
}

RationalNumber RationalNumber::operator+(const RationalNumber& b)
{
	int n = this->numerator * b.denominator / gcd(this->denominator, b.denominator) + b.numerator * this->denominator / gcd(this->denominator, b.denominator);
	int d = lcm(this->denominator, b.denominator);
	int g = gcd(n, d);
	n /= g;
	d /= g;
	return RationalNumber(n, d);
}
RationalNumber RationalNumber::operator-(const RationalNumber& b)
{
	int n = this->numerator * b.denominator / gcd(this->denominator, b.denominator) - b.numerator * this->denominator / gcd(this->denominator, b.denominator);
	int d = lcm(this->denominator, b.denominator);
	int g = gcd(n, d);
	n /= g;
	d /= g;
	return RationalNumber(n, d);
}
RationalNumber RationalNumber::operator*(const RationalNumber& b)
{
	int n = this->numerator * b.numerator;
	int d = this->denominator * b.denominator;
	int g = gcd(n, d);
	n /= g;
	d /= g;
	return RationalNumber(n, d);
}
RationalNumber RationalNumber::operator/(RationalNumber& b)
{
	RationalNumber t(b.denominator, b.numerator);
	return *this * t;
}

int main()
{
	RationalNumber c(7, 3), d(3, 9), x;
	c.printRational();
	cout << " + ";
	d.printRational();
	cout << " = ";
	x = c + d; // test overloaded operators + and =
	x.printRational();
	cout << '\n';
	c.printRational();
	cout << " - ";
	d.printRational();
	cout << " = ";
	x = c - d; // test overloaded operators - and =
	x.printRational();
	cout << '\n';
	c.printRational();
	cout << " * ";
	d.printRational();
	cout << " = ";
	x = c * d; // test overloaded operators * and =
	x.printRational();
	cout << '\n';
	c.printRational();
	cout << " / ";
	d.printRational();
	cout << " = ";
	x = c / d; // test overloaded operators / and =
	x.printRational();
	cout << '\n';
	c.printRational();
	cout << " is:\n";
	// test overloaded greater than operator
	cout << ((c > d) ? " > " : " <= ");
	d.printRational();
	cout << " according to the overloaded > operator\n";
	// test overloaded less than operator
	cout << ((c < d) ? " < " : " >= ");
	d.printRational();
	cout << " according to the overloaded < operator\n";
	// test overloaded greater than or equal to operator
	cout << ((c >= d) ? " >= " : " < ");
	d.printRational();
	cout << " according to the overloaded >= operator\n";
	// test overloaded less than or equal to operator
	cout << ((c <= d) ? " <= " : " > ");
	d.printRational();
	cout << " according to the overloaded <= operator\n";
	// test overloaded equality operator
	cout << ((c == d) ? " == " : " != ");
	d.printRational();
	cout << " according to the overloaded == operator\n";
	// test overloaded inequality operator
	cout << ((c != d) ? " != " : " == ");
	d.printRational();
	cout << " according to the overloaded != operator" << endl;
	return 0;
} // end main