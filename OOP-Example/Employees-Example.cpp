#include <iostream>

using namespace std;

class Employee {
public:
	Employee(char* theName = " ", float thePayRate = 0);
	Employee(const Employee& other);
	Employee& operator=(const Employee& other);
	~Employee();

	char* getName() const;
	float getPayRate() const;

	float pay(float hoursWorked) const;

protected:
	char* name;
	float payRate;
}; 

Employee::Employee(char* theName = " ", float thePayRate = 0)
{
	name = new char[strlen(theName) + 1];
	strcpy(name, theName);

	payRate = thePayRate;
}

Employee::Employee(const Employee& other)
{
	name = new char[strlen(other.getName()) + 1];
	strcpy(name, other.getName());

	payRate = other.getPayRate();
}

Employee& Employee::operator=(const Employee& other)
{
	if (this != &other)
	{
		delete[] name;
		name = new char[strlen(other.getName()) + 1];
		strcpy(name, other.getName());
		payRate = other.getPayRate();
	}

	return *this;
}


char* Employee::getName() const
{
	return name;
}

float Employee::getPayRate() const
{
	return payRate;
}

float Employee::pay(float hoursWorked) const
{
	return hoursWorked * payRate;
}

class Manager : public Employee {
public:
	Manager(char* theName,
		float thePayRate,
		bool isSalaried);

	bool getSalaried() const;

	float pay(float hoursWorked) const;

protected:
	bool salaried;
};

Manager::Manager(char* theName,
	float thePayRate,
	bool isSalaried)
	: Employee(theName, thePayRate)
{
	salaried = isSalaried;
}

bool Manager::getSalaried() const
{
	return salaried;
}

float Manager::pay(float hoursWorked) const
{
	if (salaried)
		return payRate;
	/* else */
	return Employee::pay(hoursWorked);
}
