#include <iostream>
#include <string>
#include "HugeInteger.h"

using namespace std;
HugeInteger::HugeInteger(int initValue)
{
	int cnt = 0;
	while (initValue) {
		integer[cnt] = initValue % 10;
		initValue /= 10;
		cnt++;
	}
	while (cnt < 40) {
		integer[cnt] = 0;
		cnt++;
	}
}
HugeInteger::HugeInteger(const char* inStr) {
	string initStr(inStr);
	for (int i = 0; i < initStr.length(); i++) {
		integer[i] = initStr[initStr.length() - 1 - i] - '0';
	}

	for (int i = initStr.length(); i < 40; i++)
		integer[i] = 0;
}

HugeInteger HugeInteger::add(const HugeInteger& addValue)
{
	HugeInteger t(*this);
	for (int i = 0; i < 40; i++) {
		t.integer[i] += addValue.integer[i];
		if (t.integer[i] >= 10) {
			t.integer[i] %= 10;
			t.integer[i + 1]++;
		}
	}
	return t;
}

HugeInteger HugeInteger::add(int addValue)
{
	return add(HugeInteger(addValue));
}

HugeInteger HugeInteger::add(const char* addValue)
{
	return add(HugeInteger(addValue));
}

HugeInteger HugeInteger::subtract(const HugeInteger& minusValue)
{
	HugeInteger t(*this);
	if (minusValue.isGreaterThan(t)) throw "Unable to deal with negative numbers...";
	for (int i = 0; i < 40; i++) {
		t.integer[i] -= minusValue.integer[i];
		if (t.integer[i] < 0) {
			t.integer[i] += 10;
			t.integer[i + 1]--;
		}
	}
	return t;
}
HugeInteger HugeInteger::subtract(int minusValue)
{
	return subtract(HugeInteger(minusValue));
}
HugeInteger HugeInteger::subtract(const char* minusValue)
{
	return subtract(HugeInteger(minusValue));
}

bool HugeInteger::isEqualTo(const HugeInteger& compareValue) const
{
	for (int i = 0; i < 40; i++) {
		if (this->integer[i] != compareValue.integer[i])
			return false;
	}
	return true;
}

bool HugeInteger::isNotEqualTo(const HugeInteger& compareValue)const
{
	return !isEqualTo(compareValue);
}

bool HugeInteger::isGreaterThan(const HugeInteger& compareValue)const
{
	int ptrA = 39, ptrB = 39;

	for (; ptrA >= 0; ptrA--)
		if (integer[ptrA])break;
	for (; ptrB >= 0; ptrB--)
		if (compareValue.integer[ptrB])break;
	if (ptrA > ptrB) return true;
	else if (ptrA < ptrB)return false;
	else {
		while (ptrA >= 0) {
			if (integer[ptrA] > compareValue.integer[ptrA])return true;
			else if (integer[ptrA] < compareValue.integer[ptrA])return false;
			ptrA--;
		}
	}
	return false;
}

bool HugeInteger::isLessThan(const HugeInteger& compareValue)const
{
	return compareValue.isGreaterThan(*this);
}

bool HugeInteger::isGreaterThanOrEqualTo(const HugeInteger& compareValue)const
{
	return (isEqualTo(compareValue) || isGreaterThan(compareValue));
}

bool HugeInteger::isLessThanOrEqualTo(const HugeInteger& compareValue)const
{
	return compareValue.isGreaterThanOrEqualTo(*this);
}

bool HugeInteger::isZero()const
{
	for (int i = 0; i < 40; i++) {
		if (integer[i])return false;
	}
	return true;
}

void HugeInteger::input(const char* inValue)
{
	string setValue(inValue);
	for (int i = 0; i < setValue.length(); i++) {
		integer[i] = inValue[setValue.length() - 1 - i] - '0';
	}

	for (int i = setValue.length(); i < 40; i++)
		integer[i] = 0;
}

void HugeInteger::output() const
{
	int i = 39;
	while (!integer[i] && i)i--;
	for (; i >= 0; i--) {
		cout << integer[i];
	}
}

ostream& operator<<(ostream& out, HugeInteger obj)
{
	int i = 39;
	while (!obj.integer[i] && i)i--;
	for (; i >= 0; i--) {
		out << obj.integer[i];
	}
	return out;
}

int main()
{
	HugeInteger hi1(7654321), hi2(7891234), hi3("5"), hi4(0);
	cout << hi1 << " + " << hi2 << " = " << hi1.add(hi2) << endl;
	cout << hi2 << " - " << hi3 << " = " << hi2.subtract(hi3) << endl;
	hi1.input("7654321");
	hi2.input("7891234");
	cout << hi1 << " is " << (hi1.isEqualTo(HugeInteger(7654321)) ? " " : "not ") << "equal to " << "7654321." << endl;
	cout << hi1 << " is " << (hi1.isEqualTo(HugeInteger(7891234)) ? " " : "not ") << "equal to " << "7891234." << endl;
	cout << hi2 << " is " << (hi2.isGreaterThan(hi1) ? " " : "not ") << "greater than " << hi1 << endl;
	cout << hi3 << " is " << (hi3.isLessThan(hi2) ? " " : "not ") << "less than " << hi2 << endl;
	cout << hi3 << " is " << (hi3.isLessThanOrEqualTo(HugeInteger(5)) ? " " : "not ") << "less than or euqal to " << "5." << endl;
	cout << hi4 << " is " << (hi4.isGreaterThanOrEqualTo(HugeInteger(0)) ? " " : "not ") << "greater than or equal to " << "0." << endl;
	cout << "hi4 is " << (hi4.isZero() ? " " : "not ") << "zero." << endl;
	return 0;
}