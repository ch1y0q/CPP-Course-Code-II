#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <string>
#include "Array.h"

using namespace std;

template <typename T>
istream& operator>>(istream& input, Array<T>& a)
{
	for (size_t i = 0; i < a.size; ++i)
		input >> a.ptr[i];

	return input; 
}

template <typename T>
ostream& operator<<(ostream& output, const Array<T>& a)
{
	for (size_t i = 0; i < a.size; ++i)
	{
		output << a.ptr[i] << endl;
	}
	return output;
}

int main()
{
	Array<int> a(3);
	Array<std::string> s;
	a[0] = 1, a[1] = 2, a[2] = 3;
	cout << "a[0]: "<<a[0] << endl;
	Array<int> b = a;
	cout << "b[0]: " << b[0] << endl;
	cout << "a is not equal to b: " << boolalpha << (a != b) << endl;
	cout << "size of a: "<<a.getSize() << endl;

	s[0] = "Hello ", s[1] = "world.", s[9] = "eof";
	cout << "size of s: " << s.getSize() << endl;
	cout << s;
	cin >> a;
	cout << a;
}