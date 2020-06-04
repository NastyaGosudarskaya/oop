#ifndef CBINARYTREE_H_INCLUDED
#define CBINARYTREE_H_INCLUDED

#pragma once
#include "CTreeNode.h"
#include <fstream>
class CBinaryTree
{
private:
	CTreeNode *root;
public:
	CBinaryTree(const char * filename);//����������� ����������� � csv-�����
	~CBinaryTree();//����������, �� ������� ������

	void push(CTreeNode *p);//��������� ����� �� ������
	void pull(CTreeNode *p);//���������
	void printtree();//���� �������� ������
	void print_for_num(int num);//���� ��� ����� �� ������ �����
	void print_trains_for_dest(string dest);//���� ��� �����, �� ����� �� ����� �������
	void del_for_num(int num);
};

#endif // CBINARYTREE_H_INCLUDED