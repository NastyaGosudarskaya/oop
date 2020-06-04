#ifndef CTREENODE_H_INCLUDED
#define CTREENODE_H_INCLUDED

#pragma once
#include <string>
#include <iostream>
using namespace std;
class CTreeNode
{
private:
	int m_Trainnumber;//номер поїзда
	string m_Destination;//станція призначення
	string m_Departuretime;//час відправлення
	CTreeNode *l;//лівий нащадок
	CTreeNode *r;//правий нащадок
public:
	CTreeNode();//
	CTreeNode(int a, string b, string c);

	string getdepart();//отримання значення часу відправлення
	string getdest();//отримання значення станції призначення
	int getnum();//отримання значення номера поїзда
	CTreeNode* getr();//отримання значення правого нащадку
	CTreeNode* getl();//отримання значення лівого нащадку

	void setdepart(string depart);//встановлювання значення часу відправлення
	void setdest(string dest);//встановлювання значення станції призначення
	void setnum(int num);//встановлювання значення номера поїзда
	void setr(CTreeNode *left);//встановлювання значення правого нащадку
	void setl(CTreeNode *right);//встановлювання значення лівого нащадку
	
	void printnode();//друк вузла
};

#endif // CTREENODE_H_INCLUDED