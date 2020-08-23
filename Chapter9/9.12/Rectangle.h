#pragma once
#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
public:
	Rectangle();
	void set();
	bool square() const;
	bool isRectangle() const;
	void distance();
	double getLength() const;
	double getWidth() const;
	double getArea() const;
	double getPerimeter() const;
private:
	double x[4], y[4];
	bool isRect;
	double dis[6];
};
#endif