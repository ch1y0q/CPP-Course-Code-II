#include <iostream>
#include "Strings.h"
using namespace std;

std::ostream& operator<<(std::ostream& output, const String& s)
{
	for (int i = 0; i < s.length; ++i)
		output << s.sPtr[i];
	return output;
}

String::String(const char* const str)
{
	length = strlen(str);
	sPtr = (char*)malloc(sizeof(char) * length);
	for (int i = 0; i < length; ++i)
		if (sPtr) {
			*(sPtr + i) = *(str + i);
		}
}

String::String(const String& inStr)
{
	length = inStr.length;
	sPtr = (char*)malloc(sizeof(char) * length);
	for (int i = 0; i < length; ++i) {
		if (sPtr) {
			*(sPtr + i) = *(inStr.sPtr + i);
		}
	}
}

String::~String()
{
	free(sPtr);
}

const String& String::operator=(const String& inStr) {
	length = inStr.length;
	sPtr = (char*)malloc(sizeof(char) * length);
	for (int i = 0; i < length; ++i) {
		if (sPtr) {
			*(sPtr + i) = *(inStr.sPtr + i);
		}
	}
	return *this;
}

String String::operator+(const String& inStr) {
	String str;
	str.length = length + inStr.length;
	str.sPtr = (char*)malloc(sizeof(char) * str.length);

	for (int i = 0; i < length; ++i) {
		if (str.sPtr) {
			*(str.sPtr + i) = *(sPtr + i);
		}
	}

	char* t = inStr.sPtr;
	char* s = str.sPtr + length;
	if (s) while (*s++ = *t++);
	/* equivalent to:
	for (int i = 0; i < inStr.length; ++i) {
		*(str.sPtr + i + length) = *(inStr.sPtr + i);
	}
	*/
	return str;
}

int main()
{
	String string1, string2("The date is");
	String string3(" August 1, 1993");
	// test overloaded operators
	cout << "string1 = string2 + string3\n";
	string1 = string2 + string3; // tests overloaded = and + operator
	cout << "\"" << string1 << "\" = \"" << string2 << "\" + \""
		<< string3 << "\"" << endl;
	return 0;
}