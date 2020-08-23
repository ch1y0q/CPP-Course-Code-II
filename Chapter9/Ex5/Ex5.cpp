#include <iostream>
#include "IntegerSet.h"
using namespace std;

IntegerSet::IntegerSet()
{
	for (int i = 0; i <= 100; ++i) a[i] = 0;
}

IntegerSet::IntegerSet(int init[], int size)
{
	for (int i = 0; i <= 100; ++i) a[i] = 0;
	for (int i = 0; i < size; ++i) a[init[i]] = 1;
}

IntegerSet IntegerSet::unionOfSets(IntegerSet inSet) const
{
	IntegerSet s;
	for (int i = 0; i <= 100; ++i)
		if (a[i] || inSet.a[i]) s.insertElement(i);
	return s;
}

IntegerSet IntegerSet::intersectionOfSets(IntegerSet inSet)const
{
	IntegerSet s;
	for (int i = 0; i <= 100; ++i)
		if (a[i] && inSet.a[i])s.insertElement(i);
	return s;
}

void IntegerSet::insertElement(int value)
{
	if (validEntry(value))
		a[value] = 1;
	else
		throw "invalid value";
}

void IntegerSet::deleteElement(int value)
{
	if (validEntry(value))
		a[value] = 0;
	else
		throw "invalid value";
}

void IntegerSet::printSet()const
{
	cout << "{	";
	for (int i = 0; i <= 100; ++i)
		if (a[i]) cout << i << "	";
	cout << "}" << endl;
}

bool IntegerSet::isEqualTo(IntegerSet inSet)
{
	for (int i = 0; i <= 100; ++i) {
		if (inSet.a[i] != a[i])return false;
	}
	return true;
}

bool IntegerSet::validEntry(int index) const
{
	if (index < 0 || index>100)return false;
	else return true;
}

void IntegerSet::inputSet()
{
	int t;
	cout << "Enter an element (-1 to end): ";
	cin >> t;
	while (t != -1) {
		insertElement(t);
		cout << "Enter an element (-1 to end): ";
		cin >> t;
	}
	cout << "Entry complete" << endl;
}

int main()
{
	IntegerSet a;
	IntegerSet b;
	IntegerSet c;
	IntegerSet d;
	cout << "Enter set A:\n";
	a.inputSet();
	cout << "\nEnter set B:\n";
	b.inputSet();
	/* Write call to unionOfSets for object a£¬passing
	b as argument and assigning the result to C */
	c = a.unionOfSets(b);
	/* Write call to intersectionOfSets for object a
		passing b as argument and assigning the result to d */
	d = a.intersectionOfSets(b);
	cout << "\nUnion of A and B is: \n";
	c.printSet();
	cout << "Intersection of A and B is:\n";
	d.printSet();
	if (a.isEqualTo(b))
		cout << "Set A is equal to set B\n";
	else
		cout << "Set A is not equal to set B\n";
	cout << "\nInserting 77 into set A...\n";
	a.insertElement(77);
	cout << "Set A is now:\n";
	a.printSet();
	cout << "\nDeleting 77 from set A...\n";
	a.deleteElement(77);
	cout << "Set A is now: \n";
	a.printSet();

	const int arraySize = 10;
	int intArray[arraySize] = { 25, 67, 2, 9, 99, 105, 45, -5, 100, 1 };
	IntegerSet e(intArray, arraySize);
	cout << "\nSet e is:\n";
	e.printSet();
	cout << endl;
	return 0;
}