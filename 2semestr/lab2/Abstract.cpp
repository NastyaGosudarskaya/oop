#include "Abstract.h"
void Person::SetF_name(string str)
{
	f_name = str;
}
void Person::SetL_name(string str)
{
	l_name = str;
}
void Person::SetAge(int n)
{
	age = n;
}
string Person::GetF_name()
{
	return f_name;
}
string Person::GetL_name()
{
	return l_name;
}
int Person::GetAge()
{
	return age;
}


Employee::Employee(const Employee &e)
{
	this->f_name = e.f_name;
	this->l_name = e.l_name;
	this->age = e.age;
	this->department = e.department;
	this->salary = e.salary;
	this->id = e.id;
}
Employee& Employee::operator=(const Employee &e)
{
	this->f_name = e.f_name;
	this->l_name = e.l_name;
	this->age = e.age;
	this->department = e.department;
	this->salary = e.salary;
	this->id = e.id;
	return *this;
}
void Employee::SetSalary(int s)
{
	this->salary = s;
}
void Employee::SetDepartment(string dept)
{
	this->department = dept;
}
void Employee::SetId(int n)
{
	this->id = n;
}
int Employee::GetId()
{
	return id;
}
string Employee::GetDepartment()
{
	return department;
}
void Employee::Display(bool a)// a=false - subordinates outputing, 
{
	if (a == false)
	{
		cout << "\tEmployment type: employee" << endl;
		cout << "\tid: " << id << endl;
		cout << "\t" << l_name << " " << l_name;
		cout << " age: " << age << " ";
		cout << "salary: " << salary << endl;
	}
	if (a == true)
	{
		cout << "Employment type: employee" << endl;
		cout << "id: " << id << endl;
		cout << l_name << " " << f_name << " ";
		cout << "age: " << age << " ";
		cout << "salary: " << salary << endl;
		cout << "department: " << department << endl;
	}
	cout << endl;
}


Manager::Manager(const Manager &m)
{
	this->f_name = m.f_name;
	this->l_name = m.l_name;
	this->age = m.age;
	this->department = m.department;
	this->salary = m.salary;
	this->id = m.id;
	this->subordinates.assign(m.subordinates.begin(), m.subordinates.end());
}
Manager& Manager::operator=(const Manager &m)
{
	this->f_name = m.f_name;
	this->l_name = m.l_name;
	this->age = m.age;
	this->department = m.department;
	this->salary = m.salary;
	this->id = m.id;
	this->subordinates.assign(m.subordinates.begin(), m.subordinates.end());
	return *this;
}
void Manager::Display(bool a)
{
	cout << "Employment type: manager" << endl;
	cout << "id: " << id << endl;
	cout << l_name << " " << f_name << " ";
	cout << "age: " << age << " ";
	cout << "salary: " << salary << endl;
	cout << "department: " << department << endl;
	cout << "Subordinates:" << endl;
	if (a == false) this->DisplaySubordinates();
	if (a == true) cout << "\t\tnone" << endl;
}
Person* Manager::AddSubordinate(Person *p)
{
	if (typeid(*p) == typeid(Employee))
	{
		if (dynamic_cast<Employee*>(p)->GetDepartment() == this->department)
		{
			subordinates.push_back(p);
		}
	}
	return p;
}


void Manager::DeleteSubordinateForId(int id)
{
	list<Person*>::iterator it = subordinates.begin();
	while (it != subordinates.end())
	{
		if (dynamic_cast<Employee*>(*it)->GetId() == id)
		{
			subordinates.erase(it);
			break;
		}
		it++;
	}
}
int Manager::GetSubSize()
{
	return subordinates.size();
}


void Manager::DisplaySubordinates()
{
	list<Person*>::iterator it = subordinates.begin();
	while (it != subordinates.end())
	{
		if (typeid(**it) == typeid(Employee))
		{
			dynamic_cast<Employee*>(*it)->Display(false);
		}
		it++;
	}
}