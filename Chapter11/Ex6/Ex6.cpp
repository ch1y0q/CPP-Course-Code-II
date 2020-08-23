#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

class Shape
{
public:
	Shape(string n):id("base_class_shape_of_" + n) { cout << "Shape created: "<< id  << endl; }
	~Shape() { cout << "Destruction of " << id << endl; }
	void print() { 
		cout << "----------------------" << endl;
		cout << "This is a shape: " << id << endl;
		cout << "----------------------" << endl;
	}
private:
	string id;
};

class Circle :public Shape
{
public:
	Circle(double r, string n):radius(r),id(n), Shape(n) { cout << "Circle created: "<< id  << endl; }
	~Circle() { cout << "Destruction of " << id << endl; }
	double area() { return 3.141592654 * radius * radius; }
	void print() {
		cout << "----------------------" << endl;
		cout << "This is a Circle: " << id << endl;
		cout << "Radius: " << radius << endl;
		cout << "Area: " << fixed << setprecision(2) << area() << endl;
		cout << "----------------------" << endl; 
	}
private:
	double radius;
	string id;
};

class Triangle : public Shape
{
public:
	Triangle(double x, double y, double z, string n):a(x),b(y),c(z),id(n), Shape(n) { cout << "Triangle created: "<< id  << endl; }
	~Triangle() { cout << "Destruction of " << id << endl; }
	double area() { double p = (a + b + c) / 2; return sqrt(p*(p-a)*(p-b)*(p-c)); }
	void print() {
		cout << "----------------------" << endl;
		cout << "This is a Triangle: " << id << endl;
		cout << "Lengths: " << a << "	" << b << "	" << c << endl;
		cout << "Area: " << fixed << setprecision(2) << area() << endl;
		cout << "----------------------" << endl;
	}
private:
	double a,b,c;
	string id;
};

class Rectangle : public Shape
{
public:
	Rectangle(double x, double y, string n) :a(x), b(y), id(n),Shape(n) { cout << "Rectangle created: "<< id  << endl; }
	~Rectangle() { cout << "Destruction of " << id << endl; }
	double area() { return 1.0 * a * b; }
	void print() {
		cout << "----------------------" << endl;
		cout << "This is a Rectangle: " << id << endl;
		cout << "Length: " << a << endl;
		cout << "Width: " << b << endl;
		cout << "Area: " <<  area() << endl;
		cout << "----------------------" << endl;
	}
private:
	double a, b;
	string id;
};

class Square : public Rectangle
{
public:
	Square(double x, string n) : a(x), id(n), Rectangle(x, x, "base_class_rectangle_of_" + n) { cout << "Square created: "<< id  << endl; }
	~Square() { cout << "Destruction of " << id << endl; }
	Circle incircle() { return Circle(a/2,"incircle of "+id); }
	double area() { return 1.0 * a * a; }
	void print() {
		cout << "----------------------" << endl;
		cout << "This is a Square: " <<id<< endl;
		cout << "Length: " << a << endl;
		cout << "Incircle: ";
		incircle().print();
		cout << "Area: " << area() << endl;
		cout << "----------------------" << endl;
	}
private:
	double a;
	string id;
};

int main()
{
	Square S1(1, "S1");
	Triangle T1(3, 4, 5, "T1");
	Rectangle R1(1, 2, "R1");
	Circle C1(1, "C1");
	S1.print();
	cout << endl << "*****************************" << endl<<endl;
	T1.print();
	cout << endl << "*****************************" << endl << endl;
	R1.print();
	cout << endl << "*****************************" << endl << endl;
	C1.print();
	return 0;
}