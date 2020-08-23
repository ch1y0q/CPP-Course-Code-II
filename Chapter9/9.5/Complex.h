#ifndef COMPLEX_HH
#define COMPLEX_HH
// Why: https://stackoverflow.com/questions/13357834/errors-when-compiling-complex-number-class-in-c

class Complex
{
public:
	Complex(double, double);
	void add(Complex c);
	void minus(Complex c);
	void print();
private:
	double real, imaginary;
};
#endif