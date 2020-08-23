#include <iostream>
using namespace std;

class A
{
public:
	A(int i):x(i)
	{
		cout << "A constructor" << endl;
	}
	~A()
	{
		cout << "A destructor" << endl;
	}
private:
	int x;
};

class B : public A
{
public:
	B(int a, int b) :A(a),y(b)
	{
		cout << "B constructor" << endl;
	}
	~B()
	{
		cout << "B destructor" << endl;
	}
private:
	int y;
};

class C : public A
{
public:
	C(int a, int b, int c) :A(a), a(c),y(b)
	{
		cout << "C constructor" << endl;
	}
	~C()
	{
		cout << "C destructor" << endl;
	}
private:
	A a;
	int y;
};

int main()
{
	A a(1);
	B b(2, 3);
	C c(4, 5, 6);
	return 0;
}