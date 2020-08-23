#include <iostream>
#include <iomanip>
#include "SimpleCalculator.h"

using namespace std;

double SimpleCalculator::add(double a, double b)
{
	return a + b;
}

double SimpleCalculator::substract(double a, double b)
{
	return a - b;
}

double SimpleCalculator::multiply(double a, double b)
{
	return a * b;
}

double SimpleCalculator::divide(double a, double b)
{
	return a / b;
}

int main()
{
	SimpleCalculator sc;
	double a = 10.0, b = 20.0;
	cout << "The value of a is: " << a << endl;
	cout << "The value of b is: " << b << endl;
	cout << endl;
	cout << fixed;
	cout << "Adding a and b yields " << setprecision(3) << sc.add(a, b) << endl;
	cout << "Subtracting a and b yields " << setprecision(3) << sc.substract(a, b) << endl;
	cout << "multiplying a by b yields " << setprecision(3) << sc.multiply(a, b) << endl;
	cout << "dividing a by b yields " << setprecision(3) << sc.divide(a, b) << endl;
	return 0;
}