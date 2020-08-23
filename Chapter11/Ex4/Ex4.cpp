#include <iostream>
using namespace std;
class MyBase {
	int x;
public:
	MyBase(int a) :x(a) {}
	int getX() { cout << "getX() called " << endl; return x; }
};
class MyDerived : public MyBase {
	int y;
public:
	MyDerived(int a) :y(a), MyBase(a + 4) {}
	int getY() { cout << "getY() called " << endl; return y; }
};
int main()
{
	MyBase a(2),* p = &a;
	MyDerived b(4),* q = &b;
	MyBase& c = a;
	MyBase& d = b;
	cout << a.getX() << " " << p->getX()<<endl;
	cout << b.getY() << " "<< q-> getY() <<endl<< b.getX() << " " << q-> getX()<<endl;
	a = b;
	cout << a.getX() << " "<<endl; // << a.getY() << endl;		ERROR
	p = q;
	cout << p->getX() << " "<<endl; // << p->getY() << endl;	ERROR
	cout << c.getX() << " " << d.getX() << " "<<endl; // << d.getY() << endl ;	ERROR
	// b= a;	ERROR
	cout << b.getX() << " " << b.getY() << endl;
}
