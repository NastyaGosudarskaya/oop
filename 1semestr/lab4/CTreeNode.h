#ifndef CTREENODE_H_INCLUDED
#define CTREENODE_H_INCLUDED

#pragma once
#include <string>
#include <iostream>
using namespace std;
class CTreeNode
{
private:
	int m_Trainnumber;//����� �����
	string m_Destination;//������� �����������
	string m_Departuretime;//��� �����������
	CTreeNode *l;//���� �������
	CTreeNode *r;//������ �������
public:
	CTreeNode();//
	CTreeNode(int a, string b, string c);

	string getdepart();//��������� �������� ���� �����������
	string getdest();//��������� �������� ������� �����������
	int getnum();//��������� �������� ������ �����
	CTreeNode* getr();//��������� �������� ������� �������
	CTreeNode* getl();//��������� �������� ����� �������

	void setdepart(string depart);//�������������� �������� ���� �����������
	void setdest(string dest);//�������������� �������� ������� �����������
	void setnum(int num);//�������������� �������� ������ �����
	void setr(CTreeNode *left);//�������������� �������� ������� �������
	void setl(CTreeNode *right);//�������������� �������� ����� �������
	
	void printnode();//���� �����
};

#endif // CTREENODE_H_INCLUDED