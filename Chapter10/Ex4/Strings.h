#ifndef STR_H
#define STR_H
#include <iostream>
using namespace std;

class String
{
	friend std::ostream& operator<<(std::ostream& output, const String& s);
public:
	String(const char* const = ""); // conversion constructor
	String(const String&); // copy constructor
	~String(); // destructor
	const String& operator=(const String&);
	String operator+(const String&);
private:
	char* sPtr; // pointer to start of string
	int length; // string length
}; // end class String
#endif