#include <iostream>
#include <vector>

using namespace std;

template <typename T>
bool palindrome(vector<T> &v)
{
	auto it = v.cbegin();
	auto rit = v.crbegin();
	for (; it < v.cend() && rit < v.crend(); ++it,++rit) {
		if (*it != *rit) return false;
	}
	return true;
}

int main()
{
	vector<int> v1;
	vector<char> v2;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(2);
	v1.push_back(1);

	v2.push_back('a');
	v2.push_back('b');
	v2.push_back('c');
	v2.push_back('b');

	cout << "v1 is " << (palindrome(v1) ? "" : "not ") << "a palindrome." << endl;
	cout << "v2 is " << (palindrome(v2) ? "" : "not ") << "a palindrome." << endl;
	return 0;
}