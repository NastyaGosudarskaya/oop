#include <cstdio>
#include <cstdlib>
#include "CBinaryTree.h"
int main()
{
	CBinaryTree trains("trains.csv");
	trains.printtree();
	cout << "Outputing information about train for its number"<<endl;
	trains.print_for_num(11);
	cout << "Outputing information about train for its destination" << endl;
	trains.print_trains_for_dest("Kharkiv");
	cout << "Outputing information about train after deleting" << endl;
	trains.del_for_num(12);
	trains.printtree();
	system("pause");
	return 0;
}