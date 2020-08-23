#include <iostream>
#include <string>
using namespace std;

class Date
{
public:
	Date(int a, int b, int c) :year(a),month(b),day(c){}
	int getYear() { return year; }
	int getMonth() { return month; }
	int getDay() { return day; }
	void setDate(int x, int y, int z) { year = x; month = y; day = z; }
private:
	int year;
	int month;
	int day;
};

class FinalTest :public Date
{
public:
	FinalTest(string s, Date d) :name(s),Date(d){}
	FinalTest(string s) :name(s), Date(2020, 7, 1){}
	void print() {
		cout << "Title: " << name << endl;
		cout << "Test date: " << Date::getYear()<<"-"<<Date::getMonth()<<"-"<<Date::getDay()<<endl;
	}
	void setDue(Date d) {
		Date::setDate(d.getYear(),d.getMonth(),d.getDay());
	}
private:
	string name;
};

int main()
{
	FinalTest item1("C++ Test", Date(2014, 6, 2));
	item1.print();
	FinalTest item2("Java");
	item2.print();
	item2.setDue(Date(2014, 6, 10));
	item2.print();
}