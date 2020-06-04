#include "Database.h"
#include "Abstract.h"
int main()
{
	Database base;
	base.LoadFromFile("input.csv");
	base.DisplayAll();
	cout << endl <<"AFTER arranging"<< endl;
	base.ArrangeSubordinates();
	base.DisplayAll();	

	base.FireEmployee(3);
	cout << endl << "AFTER firing" << endl;
	base.DisplayAll();

	cout << endl << "AFTER" << endl;
	vector<Person*> rs = base.SQL("age", "le", "44");
	base.ShowRecordSet(rs);
	system("pause");
}