#include "CBinaryTree.h"

CBinaryTree::CBinaryTree(const char * filename)
{
	root = nullptr;
	ifstream f(filename);
	if (!f.is_open()) {
		return;
	}
	else
	{
		int num;
		string dest, depart, buf;
		while (!f.eof()) {
			f >> num;
			getline(f, buf, ';');
			getline(f, dest, ';');
			getline(f, depart);

			CTreeNode *n = new CTreeNode;
			n->setnum(num);
			n->setdest(dest);
			n->setdepart(depart);
			push(n); 
		}
		f.close();
	}
}
CBinaryTree::~CBinaryTree()
{
	pull(root);
}
void CBinaryTree::push(CTreeNode *p)
{
	if (root == nullptr) {
		root = p;
		return;
	}
	else
	{
		CTreeNode *cur = root, *par=nullptr;
		while (cur != nullptr) {
			par = cur; 
			if (p->getnum() < cur->getnum()) {
				cur = cur->getl();
			}
			else if (p->getnum() > cur->getnum()) {
				cur = cur->getr();
			}
			else if ((p->getnum() == cur->getnum()))
			{
				return;
			}
		}
		if (p->getnum() < par->getnum()) 
		{
			par->setl(p);
		}
		if (p->getnum() > par->getnum())
		{
			par->setr(p);
		}
	}
}

void CBinaryTree::pull(CTreeNode *p)
{
	if (p != nullptr) {
		pull(p->getl());
		pull(p->getr());
		delete p;
	}
}

void top_down(CTreeNode *p)
{
	if (p != nullptr) {
		p->printnode();
		top_down(p->getl());
		top_down(p->getr());
	}
}

void CBinaryTree::printtree() {
	top_down(root);
}

void CBinaryTree::print_for_num(int num)
{
	if (root == nullptr)
	{
		return;
	}
	else
	{
		CTreeNode *current = nullptr;
		current = root;
		while (current != nullptr)
		{
			if (num < current->getnum())
			{
				current = current->getl();
			}
			if (num > current->getnum())
			{
				current = current->getr();
			}
			if (num == current->getnum())
			{
				current->printnode();
				break;
			}
		}
	}
}

void print_trains_for_dest_top_down(string destin, CTreeNode *p)
{
	if (p != nullptr) {
		if (p->getdest() == destin)
		{
			p->printnode();
		}
		print_trains_for_dest_top_down(destin, p->getl());
		print_trains_for_dest_top_down(destin, p->getr());
	}
}

void CBinaryTree::print_trains_for_dest(string dest)
{
	print_trains_for_dest_top_down(dest, root);
}

void CBinaryTree::del_for_num(int num)
{
	if (root == nullptr)
	{
		return;
	}
	else
	{
		CTreeNode *current = nullptr;
		current = root;
		CTreeNode *parent=new CTreeNode;
		while (current != nullptr)
		{
			parent = current;
			if (num < current->getnum())
			{
				current = current->getl();
			}
			if (num > current->getnum())
			{
				current = current->getr();
			}
			if (num == current->getnum())
			{
				break;
			}
		}
		// якщо немає нащадків
			if (current->getl() == nullptr && current->getr() == nullptr) {
				if (current == root)  root = nullptr;
				else if (parent->getl() == current) parent->setl(nullptr);
				else parent->setr(nullptr);
				delete current;
			}
		//якщо 1 нащадок справа
			else if (current->getl() == nullptr && current->getr()!=nullptr) {
				if (current == parent->getr()) {
					parent->setr(current->getr());
				}
				else {
					parent->setl(current->getr());
				}
			}
			// якщо 1 нащадок зліва
			else if (current->getl()!=nullptr && current->getr() == nullptr) {
				if (current == parent->getr()) {
					parent->setr(current->getl());
				}
				else {
					parent->setl(current->getl());
				}
			}
			//якщо 2 нащадки
			else {
				CTreeNode *left_pivot = current->getr();
				CTreeNode *parent_pivot=current;
				while (left_pivot->getl() != nullptr)
				{
					parent_pivot = left_pivot;
					left_pivot = left_pivot->getl();
				}
				current->setnum(left_pivot->getnum());
				current->setdest(left_pivot->getdest());
				current->setdepart(left_pivot->getdepart());
				if (left_pivot==current->getr())
				{
					current->setr(left_pivot->getr());
				}
				delete left_pivot;
			}
	}
}