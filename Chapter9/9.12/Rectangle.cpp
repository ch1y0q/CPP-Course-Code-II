#include <iostream>
#include <cmath>
#include <algorithm>
#include "Rectangle.h"

using namespace std;

void Rectangle::distance()
{
	int cnt = 0;
	for (int i = 0; i < 4; ++i) {
		for (int j = i + 1; j < 4; ++j) {
			dis[cnt] = sqrt((x[j] - x[i]) * (x[j] - x[i])
				+ (y[j] - y[i]) * (y[j] - y[i]));
			cnt++;
		}
	}
	sort(dis, dis + 6);
}

void Rectangle::set()
{
	cout << "Please enter the 4 sets of coordinates of the Rectangle..." << endl;

	for (int i = 0; i < 4; ++i) {
		int cx, cy;
		cin >> cx >> cy;
		if (cx < 0 || cx > 20) {
			cout << "Invalid value. Please re-enter." << endl;
			i--;
			continue;
		}
		if (cy < 0 || cy > 20) {
			cout << "Invalid value. Please re-enter." << endl;
			i--;
			continue;
		}
		x[i] = cx;
		y[i] = cy;
	}

	distance();
	if (dis[0] && (dis[0] == dis[1]) && (dis[2] == dis[3]) && (dis[4] == dis[5]))
		isRect = true;
	else
		isRect = false;
}

Rectangle::Rectangle()
{
	set();
}

bool Rectangle::isRectangle() const
{
	return isRect;
}

bool Rectangle::square() const
{
	if (dis[0] && (dis[0] == dis[1]) && (dis[1] == dis[2]) && (dis[2] == dis[3]))
		return true;
	else
		return false;
}

double Rectangle::getWidth() const
{
	return dis[0];
}

double Rectangle::getLength() const
{
	return dis[2];
}

double Rectangle::getArea() const
{
	return (getWidth() * getLength());
}

double Rectangle::getPerimeter() const
{
	return 2 * (getWidth() + getLength());
}

int main()
{
	Rectangle rect;
	if (rect.isRectangle())
	{
		if (rect.square())
			cout << "Square." << endl;
		else
			cout << "Rectangle." << endl;
		cout << "Length: " << rect.getLength()
			<< "Width: " << rect.getWidth() << endl;
		cout << "Perimeter: " << rect.getPerimeter() << endl;
		cout << "Area: " << rect.getArea() << endl;
	}
	else {
		cout << "Not a rectangle." << endl;
	}
	return 0;
}