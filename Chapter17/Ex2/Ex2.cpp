#include <iostream>

using namespace std;

class Item
{
public:
	Item(int v) :value(v)
	{
		cout << "Item " << v << " constructor called" << endl;
		if (value == 3) throw runtime_error("An exception was thrown");
	}
	~Item()
	{
		cout << "Item " << value << " destructor called" << endl;
	}
private:
	int value;
};

int main()
{
	try {
		Item i1(1);
		Item i2(2);
		Item i3(3);
		Item i4(4);
	}
	catch (runtime_error& re) {
		cout << re.what() << endl;
	}
	return 0;
}