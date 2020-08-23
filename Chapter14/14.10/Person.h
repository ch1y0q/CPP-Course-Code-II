#ifndef PERSON_H
#define PERSON_H

#include<string>

class Person
{
public:
	Person(int, std::string, std::string, int);

	void setId(int);
	int getId() const;

	void setLastName(const std::string&);
	std::string getLastName() const;

	void setFirstName(const std::string&);
	std::string getFirstName() const;

	void setAge(int);
	int getAge() const;
private:
	char lastName[15];
	char firstName[10];
	int age;
	int id;
};

#endif

