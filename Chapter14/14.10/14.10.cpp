#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "Person.h"

using namespace std;

void Person::setId(int idValue)
{
	id = idValue;
}

int Person::getId() const
{
	return id;
}

void Person::setLastName(const string& lastNameString)
{
	int length = lastNameString.size();
	length = (length < 15 ? length : 14);
	lastNameString.copy(lastName, length);
	lastName[length] = '\0';
}

string Person::getLastName() const
{
	return lastName;
}

void Person::setFirstName(const string& firstNameString)
{
	int length = firstNameString.size();
	length = (length < 10 ? length : 9);
	firstNameString.copy(firstName, length);
	firstName[length] = '\0';
}

string Person::getFirstName() const
{
	return firstName;
}

void Person::setAge(int ageValue)
{
	age = ageValue;
}

int Person::getAge() const
{
	return age;
}

Person::Person(int inId = 0, string lastName = "unassigned", string firstName = "", int inAge = 0) :age(inAge), id(inId)
{
	setFirstName(firstName);
	setLastName(lastName);
}

// obtain id-number value from user
int getId(const char* const prompt)
{
	int id;
	// obtain id-number value
	do
	{
		cout << prompt << " (1 - 100): ";
		cin >> id;
	} while (id < 1 || id > 100);
	return id;
}


void initData(fstream& initFile)
{
	Person record;
	// move file-position pointer to the start
	initFile.seekp(0);
	for (int i = 1; i <= 100; ++i) {
		initFile.write(reinterpret_cast<const char*>(&record), sizeof(Person));
	} // end if
}

void newRecord(fstream& insertInFile)
{
	// obtain number of record to create
	int id = getId("Enter new id number");
	// move file-position pointer to correct record in file
	insertInFile.seekg((id - 1) * sizeof(Person));
	// read record from file
	Person record;
	insertInFile.read(reinterpret_cast<char*>(&record), sizeof(Person));
	// create record, if record does not previously exist
	if (record.getId() == 0)
	{
		string lastName;
		string firstName;
		int age;
		// user enters last name, first name and age
		cout << "Enter lastname, firstname, age\n? ";
		cin >> lastName;
		cin >> firstName;
		cin >> age;
		// use values to populate account values
		record.setLastName(lastName);
		record.setFirstName(firstName);
		record.setAge(age);
		record.setId(id);
		// move file-position pointer to correct record in file
		insertInFile.seekp((id - 1) * sizeof(Person));
		// insert record in file
		insertInFile.write(reinterpret_cast<const char*>(&record),
			sizeof(Person));
	} // end if
	else // display error if id already exists
		cerr << "ID #" << id
		<< " already contains information." << endl;
}

void updateRecord(fstream& updateFile)
{
	int id = getId("Enter delete id number");		// get the id to delete from user
	Person record;
	updateFile.seekg((id - 1) * sizeof(Person));		// point to the correct record
	updateFile.read(reinterpret_cast<char*>(&record), sizeof(Person));	// read from nameage.dat
	if (record.getId()) {							// record exists
		string lastName;
		string firstName;
		int age;
		// user enters last name, first name and age
		cout << "Enter lastname, firstname, age\n? ";
		cin >> lastName;
		cin >> firstName;
		cin >> age;
		// use values to populate account values
		record.setLastName(lastName);
		record.setFirstName(firstName);
		record.setAge(age);
		record.setId(id);
		updateFile.seekp((id - 1) * sizeof(Person));		// point to the correct record
		updateFile.write(reinterpret_cast<const char*>(&record), sizeof(Person));	//over-write with empty record
	}
	else {
		cerr << "ID #" << id
			<< " contains NO INFO" << endl;
	}
}

void deleteRecord(fstream& deleteFile)
{
	int id = getId("Enter delete id number");		// get the id to delete from user
	Person record;
	deleteFile.seekg((id - 1) * sizeof(Person));		// point to the correct record
	deleteFile.read(reinterpret_cast<char*>(&record), sizeof(Person));	// read from nameage.dat
	if (record.getId()) {							// record exists
		Person empty;
		deleteFile.seekp((id - 1) * sizeof(Person));		// point to the correct record
		deleteFile.write(reinterpret_cast<const char*>(&empty), sizeof(Person));	//over-write with empty record
	}
	else {
		cerr << "ID #" << id
			<< " does not contain any information." << endl;
	}
}

int enterChoice()
{
	// display available options
	cout << "\nEnter your choice" << endl
		<< "1 - initialize nameage.dat with 100 empty records" << endl
		<< "2 - input 10 records with name and age" << endl
		<< "3 - update an existing record" << endl
		<< "4 - delete a record" << endl
		<< "5 - end program\n? ";

	int menuChoice;
	cin >> menuChoice; // input menu selection from user
	return menuChoice;
}

int main() {
	fstream inOutPerson("nameage.dat", ios::in | ios::out | ios::binary);
	if (!inOutPerson)
	{
		cerr << "File could not be created." << endl;
		exit(EXIT_FAILURE);
	}
	enum Choices { INIT = 1, NEW, UPDATE, DELETE, END };
	int choice;
	while ((choice = enterChoice()) != END) {
		switch (choice) {
		case INIT:
			initData(inOutPerson);
			break;
		case NEW:
			for (int i = 0; i < 10; ++i)
				newRecord(inOutPerson);
			break;
		case UPDATE:
			updateRecord(inOutPerson);
			break;
		case DELETE:
			deleteRecord(inOutPerson);
			break;
		}
		inOutPerson.clear();
	}
	inOutPerson.close();
	return 0;
}