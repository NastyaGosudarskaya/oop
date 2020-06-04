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
	CBinaryTree(const char * filename);//конструктор ініціалізації з csv-файлу
	~CBinaryTree();//деструктор, що видаляє дерево

	void push(CTreeNode *p);//додавання вузла до дерева
	void pull(CTreeNode *p);//видалення
	void printtree();//вивід бінарного дерева
	void print_for_num(int num);//вивід усіх даних по номеру поїзда
	void print_trains_for_dest(string dest);//вивід усіх поїздів, що їдуть до данної станції
	void del_for_num(int num);
};

#endif // CBINARYTREE_H_INCLUDED