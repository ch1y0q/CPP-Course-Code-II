#include <iostream>

using namespace std;

class A
{
public:
	A(int i) :v(i) { cout << i << " constructor called" << endl; }
	~A() { cout << v << " destructor called" << endl; }
private:
	int v;
};

class TestException : public runtime_error
{
public:
	TestException(const char* msg) :runtime_error(msg) {}
};

void h()
{
	A e(3);
	throw TestException("Caught TestException");
}

void g()
{
	A d(2);
	try { h(); }
	catch (logic_error& le) {		// TestException not to be caught
		cout << "In g():" << endl;
		cout << le.what() << endl;
	}
}

void f()
{
	A c(1);
	try { g(); }
	catch (logic_error& le) {		// TestException not to be caught
		cout << "In f():" << endl;
		cout << le.what() << endl;
	}
}

int main()
{
	A a(-1);
	try {
		A b(0);
		f();
	}
	catch (TestException& te) {
		cout << "In main():" << endl;
		cout << te.what() << endl;
	}
	return 0;
}