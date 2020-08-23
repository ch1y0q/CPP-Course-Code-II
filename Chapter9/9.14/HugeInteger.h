#include <ostream>
#ifndef HUGEINTEGER_H
#define HUGEINTEGER_H
class HugeInteger
{

public:
	HugeInteger(int = 0); // conversion/default constructor
	HugeInteger(const char*); // conversion constructor
	// addition operator; HugeInteger + HugeInteger
	HugeInteger add(const HugeInteger&);
	// addition operator; HugeInteger + int
	HugeInteger add(int);
	// addition operator;
	// HugeInteger + string that represents large integer value
	HugeInteger add(const char*);
	// subtraction operator; HugeInteger - HugeInteger
	HugeInteger subtract(const HugeInteger&);
	// subtraction operator; HugeInteger - int
	HugeInteger subtract(int);
	// subtraction operator;
	// HugeInteger - string that represents large integer value
	HugeInteger subtract(const char*);
	bool isEqualTo(const HugeInteger&) const; // is equal to
	bool isNotEqualTo(const HugeInteger&)const; // not equal to
	bool isGreaterThan(const HugeInteger&)const; // greater than
	bool isLessThan(const HugeInteger&)const; // less than
	bool isGreaterThanOrEqualTo(const HugeInteger&)const; // greater than
	// or equal to
	bool isLessThanOrEqualTo(const HugeInteger&)const; // less than or equal
	bool isZero()const; // is zero
	void input(const char*); // input
	void output()const; // output

private:
	int integer[40]; // 40 element array
	friend std::ostream& operator<<(std::ostream& out, HugeInteger obj); // overload <<
}; // end class HugeInteger
#endif