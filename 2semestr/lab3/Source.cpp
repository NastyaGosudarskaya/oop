#include "List.h"
#include "Iterator.h"
#include "CFile.h"

typedef CFile T;
List<T> catalog;
List<T> del;

void fdelete(const char *name, List<T>& lst, List<T>& lstdel);
void frestore(const char *name, List<T>& lst, List<T>& lstdel);
void frename_catalog(const char* filename, const char* new_filename, List<T>& lst);
void deletedate(const char* date, List<T>& lst);

int main()
{
	catalog.load("input.csv");
	cout << "At the begining"<<endl;
	catalog.Print();
	cout << endl;
	cout << "After deleting \"laba1.cpp\"" << endl;
	fdelete("laba1.cpp", catalog, del);
	catalog.Print();
	cout << endl;
	del.Print();
	cout << "After restoring \"laba1.cpp\"" << endl;
	frestore("laba1.cpp", catalog, del);
	cout << endl;
	catalog.Print();
	cout << endl;
	del.Print();
	cout << "After deleting for date" << endl;
	deletedate("29.01.2019", catalog);
	cout << endl;
	catalog.Print();
	cout <<endl<< "After renaming" << endl;
	frename_catalog("nastya.cpp","nast.cpp", catalog);
	cout << endl;
	catalog.Print();
	system("pause");
	return 0;
}

void fdelete(const char *name, List<T>& lst, List<T>& lstdel)
{
	if (name != NULL && lst.empty() != true)
	{
		List<T>::iterator it = lst.begin();
		while (it != lst.end())
		{
			if (strcmp((*it).data.getfilename(), name) == 0)
			{
				lst.splice(it, lstdel);
				break;
			}
			it++;
		}
	}
	else return;
}
void frestore(const char *name, List<T>& lst, List<T>& lstdel)
{
	if (name != NULL && lstdel.empty() != true)
	{
		List<T>::iterator it = lstdel.begin();
		while (it != lstdel.end())
		{
			if (strcmp((*it).data.getfilename(), name) == 0)
			{
				lstdel.splice(it, lst);
				break;
			}
			it++;
		}
	}
	else return;
}
void frename_catalog(const char* name, const char* newname, List<T>& lst)
{
	if (name != NULL && newname!=NULL)
	{
		List<T>::iterator it = lst.begin();
		while (it != lst.end())
		{
			if (strcmp((*it).data.getfilename(), name) == 0)
			{
				(*it).data.setfilename(newname);
				break;
			}
			it++;
		}
	}
	else return;
}
void deletedate(const char* date, List<T>& lst)
{
	if (date != NULL)
	{
		char buf[2];
		for (int i = 0; i < 2; i++)
		{
			buf[i] = date[i];
		}
		int a1 = atoi(buf);

		char buf2[2];
		for (int i = 0; i < 2; i++)
		{
			buf2[i] = date[i + 3];
		}
		int a2 = atoi(buf2);

		char buf3[4];
		for (int i = 0; i < 4; i++)
		{
			buf3[i] = date[i + 6];
		}
		int a3 = atoi(buf3);

		List<T>::iterator it = lst.begin();
		while (it != lst.end())
		{
			char buff[2];
			for (int i = 0; i < 2; i++)
			{
				buff[i]=(*it).data.getdate()[i];
			}
			int k1 = atoi(buff);

			char buff2[2];
			for (int i = 0; i < 2; i++)
			{
				buff2[i] =(*it).data.getdate()[i+3];
			}
			int k2 = atoi(buff2);

			char buff3[4];
			for (int i = 0; i < 4; i++)
			{
				buff3[i]=(*it).data.getdate()[i + 6] ;
			}
			int k3 = atoi(buff3);

			if (k3 < a3)
			{
				lst.remove(*it);                                                                                                  lst.remove(*it);
			}
			if (k3 == a3)
			{				
				if (k2 < a2)
				{
					lst.remove(*it);
				}
				if (k2 == a2)
				{
					if (k1 < a1)
					{
						lst.remove(*it);
					}
				}
			}
			it++;
		}
	}
	else return;
}