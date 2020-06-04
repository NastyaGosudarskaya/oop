#include "Database.h"
 bool Database::LoadFromFile(const char *file)
 {
	 ifstream f(file);
	 if (f.is_open())
	 {
		 int i = 0;
		 while (!f.eof())
		 {
			 Employee *p=NULL;
			 string temp;
			 getline(f, temp, ';');
			 if (stoi(temp) == 1) p = new Manager;
			 if (stoi(temp) == 0) p = new Employee;
			 getline(f, temp, ';');
			 p->SetId(stoi(temp));
			 getline(f, temp, ';');
			 p->SetL_name(temp);
			 getline(f, temp, ';');
			 p->SetF_name(temp);
			 getline(f, temp, ';');
			 p->SetAge(stoi(temp));
			 getline(f, temp, ';');
			 p->SetDepartment(temp);
			 getline(f, temp);
			 p->SetSalary(stoi(temp));
			 employees.push_back(p);
		 }
		 f.close();
		 return true;
	 }
	 else return false;
 }
 void Database::ArrangeSubordinates()
 {
	 for (int i = 0; i < employees.size(); i++)
	 {
		 if (typeid(*employees[i]) == typeid(Manager))
		 {
			 for (int j = 0; j < employees.size(); j++)
			 {
				 if (typeid(*employees[j]) == typeid(Employee))
				 {
					dynamic_cast<Manager*>(employees[i])->AddSubordinate(employees[j]);
				 }
			 }
		 }
	 }
 }
 void Database::DisplayAll()
 {
	 vector<Person*>::iterator it = employees.begin();
	 while (it != employees.end())
	 {
		 if (typeid(**it) == typeid(Employee)) 
		 {	 
			 dynamic_cast<Employee*>(*it)->Display(true);
		 }
		 if (typeid(**it) == typeid(Manager)) {
			 bool flag = false;
			 if (dynamic_cast<Manager*>(*it)->GetSubSize() == 0) flag = true;
			 dynamic_cast<Manager*>(*it)->Display(flag);
		 }
		 it++;
	 }
 }

 Person* Database::HireEmployee(Person *p)
 {
	 int i = 0;
		 employees.push_back(p);
		 if (typeid(*p) == typeid(Employee)) {
			 for (int j = 0; j < employees.size(); j++)
			 {
				 if (typeid(*employees[j]) == typeid(Manager))
				 {
					 if (dynamic_cast<Manager*>(employees[j])->GetDepartment() == dynamic_cast<Employee*>(p)->GetDepartment())
					 {
						 dynamic_cast<Manager*>(employees[j])->AddSubordinate(p);
						 i = 1;
					 }
				 }
			 }
		 }
		 if (typeid(*p) == typeid(Manager)) {
			 for (int j = 0; j < employees.size(); j++)
			 {
				 if (typeid(*employees[j]) == typeid(Employee))
				 {
					 dynamic_cast<Manager*>(employees[employees.size()-1])->AddSubordinate(employees[j]);
					 i = 1;
				 }
			 }
		 }
		 if (i == 0) return NULL;
		 else return p;
 }

 bool Database::FireEmployee(int id)
 {
	 bool f1=false;
	 vector<Person*>::iterator it = employees.begin();
	 while (it != employees.end())
	 {
		 if (typeid(**it) == typeid(Employee)) 
		 {
			 if (dynamic_cast<Employee*>(*it)->GetId() == id)
			 {
				 for (int i = 0; i < employees.size(); i++)
				 {
					 if (typeid(*employees[i]) == typeid(Manager))
					 {
						 if (dynamic_cast<Employee*>(*it)->GetDepartment() == dynamic_cast<Manager*>(employees[i])->GetDepartment())
						 {
							 dynamic_cast<Manager*>(employees[i])->DeleteSubordinateForId(id);
						 }
					 }
				 }
				 employees.erase(it);
				 f1 = true;
				 break;
			 }
		 }
		 if (typeid(**it) == typeid(Manager)) {
			 if (dynamic_cast<Manager*>(*it)->GetId() == id)
			 {
				 employees.erase(it);
				 f1 = true;
				 break;
			 }
		 }
		 it++;
	 }
	 return f1;
 }

 vector<Person*> Database::SQL(const char *field, const char * cond, const char* value)
 {
	 vector<Person*> db;
	 if (field == "age")
	 {
		 if (cond == "le")
		 {
			 vector<Person*>::iterator it = employees.begin();
			 while (it!=employees.end())
			 {
				 if ((*it)->GetAge() <= stoi(value))
				 {
					 db.push_back(*it);
				 }
				 it++;
			 }
		 }
		 if (cond == "ge")
		 {
			 vector<Person*>::iterator it = employees.begin();
			 while (it != employees.end())
			 {
				 if ((*it)->GetAge() >= stoi(value))
				 {
					 db.push_back(*it);
				 }
				 it++;
			 }
		 }
	 }
	 if (field == "salary")
	 {
		 if (cond == "le")
		 {
			 vector<Person*>::iterator it = employees.begin();
			 while (it != employees.end())
			 {
				 if (dynamic_cast<Employee*>(*it)->GetSalary() <= stoi(value))/////////////////////
				 {
					 db.push_back(*it);
				 }
				 it++;
			 }
		 }
		 if (cond == "ge")
		 {
			 vector<Person*>::iterator it = employees.begin();
			 while (it != employees.end())
			 {
				 if (dynamic_cast<Employee*>(*it)->GetSalary() >= stoi(value))/////////////////////
				 {
					 db.push_back(*it);
				 }
				 it++;
			 }
		 }
	 }
	 return db;
 }

 void Database::ShowRecordSet(vector<Person*> rs)
 {
	 vector<Person*>::iterator it = rs.begin();
	 while (it != rs.end())
	 {
		 if (typeid(**it) == typeid(Employee)) {
			 dynamic_cast<Employee*>(*it)->Display(true);
		 }
		 if (typeid(**it) == typeid(Manager)) {
			 bool flag = false;
			 if (dynamic_cast<Manager*>(*it)->GetSubSize() == 0) flag = true;
			 dynamic_cast<Manager*>(*it)->Display(flag);
		 }
		 it++;
	 }
 }