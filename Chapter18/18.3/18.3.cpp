#include <iostream>

using namespace std;

class A
{
public:
	A(int a) :v(a) {}
	bool operator==(A& a) { return v == a.v; }	// without this, == and isEqualTo won't work
private:
	int v;
};

template <typename T>
bool isEqualTo(T& a, T& b)
{
	return (a == b);
}

int main()
{
	int a = 1, b = 1, c = 2;
	A a1(1), a2(1), a3(2);
	cout << a << " equals " << b << ": " << boolalpha << isEqualTo(a, b) << endl;
	cout << a << " equals " << c << ": " << boolalpha << isEqualTo(a, c) << endl;
	cout << "a1 equals a2: " << boolalpha << isEqualTo(a1, a2) << endl;
	cout << "a1 equals a3: " << boolalpha << (a1 == a3) << endl;
	return 0;
}