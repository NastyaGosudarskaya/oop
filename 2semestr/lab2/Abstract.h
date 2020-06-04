#pragma once
#include <list>
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;
class Person {
public:
	Person() {};
	Person(string _f_name, string _l_name, int _age) : age(_age),
		f_name(_f_name), l_name(_l_name) {	}
	virtual void Display(bool) = 0;

	void SetF_name(string str);
	void SetL_name(string str);
	void SetAge(int n);
	string GetF_name();
	string GetL_name();
	int GetAge();
protected:
	string f_name;//first name
	string l_name;//last name
	int age;
};

class Employee : public Person {
public:
	Employee() {};
	Employee(string _f_name, string _l_name, int _age, int _id) :
		Person(_f_name, _l_name, _age), id(_id) {};
	Employee(const Employee &e);
	Employee& operator=(const Employee &e);
	void SetSalary(int s);
	void SetDepartment(string dept);
	void SetId(int n);
	int GetId();
	string GetDepartment();
	int GetSalary() { return salary; }
	virtual void Display(bool);
	//Add here whatever you need
protected:
	string department;
	int salary;
	int id;
};

class Manager : public Employee {
public:
	Manager() {};
	Manager(string _f_name, string _l_name, int _age, int _id) :
		Employee(_f_name, _l_name, _age, _id) {};
	Manager(const Manager &m);
	Manager& operator=(const Manager &m);
	virtual void Display(bool);
	//add an employee to the subordinates list
	Person* AddSubordinate(Person *p);
	void DisplaySubordinates();
	//Add here whatever you need
	void DeleteSubordinateForId(int id);
	int GetSubSize();
private:
	list<Person *> subordinates;//список підлеглих
};
