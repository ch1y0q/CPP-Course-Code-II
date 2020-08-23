#include <iostream>
#include <string>
#include "HugeInt.h"

using namespace std;

std::string HugeInt::toString(int start, int end) 
{
	string s = "";
	for (int i = start; i <= end; ++i)
		s += to_string(integer[i]);
	return s;
}

HugeInt HugeInt::operator+(const HugeInt& inNum) const
{
	int digit = 1;
	HugeInt t(*this);
	for (int i = 1; i < 30; i++) {
		t.integer[i] += inNum.integer[i];
		if (t.integer[i] >= 10) {
			t.integer[i] %= 10;
			t.integer[i + 1]++;
		}
		if (t.integer[i]) digit = i;
	}
	t.integer[0] = digit;
	return t;
}

HugeInt HugeInt::operator+(int inNum) const
{
	return (*this + HugeInt((long)inNum));
}

HugeInt HugeInt::operator+(const char* inNum) const
{
	return (*this + HugeInt(inNum));
}

bool HugeInt::operator==(const HugeInt& cmp) const
{
	for (int i = 0; i < 30; ++i) {
		if (integer[i] != cmp.integer[i]) {
			return false;
		}
	}
	return true;
}

bool HugeInt::operator!=(const HugeInt& cmp) const
{
	return !(*this == cmp);
}

bool HugeInt::operator<(const HugeInt& cmp) const
{
	return (cmp > * this);
}

bool HugeInt::operator<=(const HugeInt& cmp) const
{
	return (cmp >= *this);
}

bool HugeInt::operator>(const HugeInt& cmp) const
{
	if (integer[0] > cmp.integer[0]) {
		return true;
	}
	else if (integer[0] < cmp.integer[0]) {
		return false;
	}
	else {
		for (int i = integer[0]; i > 0; --i) {
			if (integer[i] > cmp.integer[i]) {
				return true;
			}
			else if (integer[i] < cmp.integer[i]) {
				return false;
			}
		}
	}
	return false;
}

bool HugeInt::operator>=(const HugeInt& cmp) const
{
	if (integer[0] > cmp.integer[0]) {
		return true;
	}
	else if (integer[0] < cmp.integer[0]) {
		return false;
	}
	else {
		for (int i = integer[0]; i > 0; --i) {
			if (integer[i] > cmp.integer[i]) {
				return true;
			}
			else if (integer[i] < cmp.integer[i]) {
				return false;
			}
		}
	}
	return true;
}

HugeInt HugeInt::operator-(const HugeInt& inNum) const
{
	int digit = 1;
	HugeInt t(*this);
	if (inNum >= t) throw "Unable to deal with negative numbers...";
	for (int i = 1; i < 30; i++) {
		t.integer[i] -= inNum.integer[i];
		if (t.integer[i] < 0) {
			t.integer[i] += 10;
			t.integer[i + 1]--;
		}
		if (t.integer[i])digit = i;
	}
	t.integer[0] = digit;
	return t;
}

HugeInt HugeInt::operator*(const HugeInt& inNum) const
{
	HugeInt t;
	int pos=1;
	for (int i = 1; i <= integer[0]; i++) {
		pos = i;
		for (int j = 1; j <= inNum.integer[0]; j++) {
			t.integer[pos] += integer[i] * inNum.integer[j];
			pos++;
		}
	}
	for (int i = 1; i < pos; i++) {
		t.integer[i + 1] += t.integer[i] / 10;
		t.integer[i] = t.integer[i] % 10;
	}
	t.integer[0] = pos - 1;
	return t;
}

// warning: brute-force
HugeInt HugeInt::operator/(const HugeInt& inNum) const
{
	if (!inNum.integer[0] || inNum.integer[0]==1 && !inNum.integer[1]) {
		throw "Divide by zero!";
	}
	if (inNum > (*this)) {
		return HugeInt(0L);
	}

	HugeInt t(1L);

	while (t * inNum <= *this && (t + 1) * inNum <= *this)
		t = t + 1;
	return t;
}

int HugeInt::getLength() const
{
	return integer[0] ? integer[0] : 1;
}

ostream& operator<<(ostream& output, const HugeInt& hi)
{
	if (!hi.integer[0])	output << 0;
	else {
		for (int i = hi.integer[0]; i > 0 ; --i) {
			output << hi.integer[i];
		}
	}
	return output;
}

HugeInt::HugeInt(long inValue)
{
	int cnt = 1;
	while (inValue) {
		integer[cnt] = inValue % 10;
		inValue /= 10;
		cnt++;
	}
	integer[0] = cnt - 1;
	while (cnt < 30) {
		integer[cnt] = 0;
		cnt++;
	}
}

HugeInt::HugeInt(const char* inStr)
{
	string initStr(inStr);

	for (int i = 1; i <= initStr.length(); i++) {
		integer[i] = initStr[initStr.length()  - i] - '0';
	}

	for (int i = initStr.length()+1; i < 30; i++)
		integer[i] = 0;

	integer[0] = initStr.length();
}

HugeInt::HugeInt(std::string inStr)
{
	for (int i = 1; i <= inStr.length(); i++) {
		integer[i] = inStr[inStr.length() - i] - '0';
	}

	for (int i = inStr.length() + 1; i < 30; i++)
		integer[i] = 0;

	integer[0] = inStr.length();
}

int main()
{
	HugeInt h1("321");
	HugeInt h2(4321);
	cout << h1<<">"<<h2<<": "<<boolalpha<< (h1 > h2)<<endl;
	cout << h1 << "<" << h2 << ": " << boolalpha << (h1 < h2)<<endl;
	cout << h1 << "!=" << h2 << ": " << boolalpha << (h1 != h2) << endl;
	cout << h1 << "+" << h2 << "= " <<  (h1 + h2) << endl;
	cout << h2 << "-" << h1 << "= " << (h2-h1) << endl;
	cout << h1 << "*" << h2 << "= " << (h2 * h1) << endl;
	h1 = HugeInt(4321);
	cout << h1 << "<=" << h2 << ": " << boolalpha << (h1 <= h2)<<endl;
	cout << h1 << "==" << h2 << ": " << boolalpha << (h1 == h2) << endl;

	HugeInt h3("123456789000000");
	HugeInt h4(4321);

	cout << h3 << "*" << h4 << "= " << (h3 * h4) << endl;
	HugeInt h5("432100");
	HugeInt h6(432);
	cout << h5 << "/" << h6 << "= " << (h5 / h6) << endl;
	return 0;
}