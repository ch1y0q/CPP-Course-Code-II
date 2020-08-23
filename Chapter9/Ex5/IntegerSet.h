#pragma once
#ifndef INTEGERSET_H
#define INTEGERSET_H
class IntegerSet {
public:
	IntegerSet();
	IntegerSet(int init[], int size);
	IntegerSet unionOfSets(IntegerSet)const;
	IntegerSet intersectionOfSets(IntegerSet)const;
	void insertElement(int);
	void deleteElement(int);
	void printSet() const;
	bool isEqualTo(IntegerSet);
	bool validEntry(int) const;
	void inputSet();
private:
	int a[101];
};
#endif