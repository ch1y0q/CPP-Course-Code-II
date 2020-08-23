#include <iostream>
#include "Complex.h"
using namespace std;

std::ostream& operator<< (std::ostream& os, const Complex& c)
{
	os << '(' << c.real << ", " << c.imaginary << ')';
	return os;
}

std::istream& operator>> (std::istream& is, Complex& c)
{
	char c1, c2;
	double r, i;
	is >> c1 >> r >> c2 >> i;
	c.real = r;
	c.imaginary = i;
	return is;
}

Complex::Complex(double realPart, double imaginaryPart)
	: real(realPart), imaginary(imaginaryPart) { }

Complex Complex::operator+(const Complex& operand2) const
{
	return Complex(real + operand2.real,
		imaginary + operand2.imaginary);
}

Complex Complex::operator-(const Complex& operand2) const
{
	return Complex(real - operand2.real,
		imaginary - operand2.imaginary);
}

Complex Complex::operator*(const Complex& operand2) const
{
	return Complex(real * operand2.real - imaginary * operand2.imaginary,
		real * operand2.imaginary + imaginary * operand2.real);
}

bool Complex::operator==(const Complex& operand2) const
{
	return (real == operand2.real && imaginary == operand2.imaginary);
}

bool Complex::operator!=(const Complex& operand2) const
{
	return (real != operand2.real || imaginary != operand2.imaginary);
}

void Complex::print() const
{
	cout << '(' << real << ", " << imaginary << ')';
}

int main()
{
	Complex x, y(4.3, 8.2), z(3.3, 1.1), k;
	cout << "Enter a complex number in the form: (a, b)\n? ";
	cin >> k; // demonstrating overloaded >>
	cout << "x: " << x << "\ny: " << y << "\nz: " << z << "\nk: "
		<< k << '\n'; // demonstrating overloaded <<
	x = y + z; // demonstrating overloaded + and =
		cout << "\nx = y + z:\n" << x << " = " << y << " + " << z << '\n';
	x = y - z; // demonstrating overloaded - and =
	cout << "\nx = y - z:\n" << x << " = " << y << " - " << z << '\n';
	x = y * z; // demonstrating overloaded * and =
	cout << "\nx = y * z:\n" << x << " = " << y << " * " << z << "\n\n";
	if (x != k) // demonstrating overloaded !=
		cout << x << " != " << k << '\n';
	cout << '\n';
	x = k;
	if (x == k) // demonstrating overloaded ==
		cout << x << " == " << k << '\n';
	return 0;
} // end main