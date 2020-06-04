#pragma once
#include "Iterator.h"
#include <stddef.h>
#include <iostream> 
#include <string> 
using namespace std;
template <class T>
class List {
	struct ListNode {
		T data;
		ListNode * next;
		ListNode() {
			next = NULL;
		}
		ListNode(T dat) {
			data = dat;
		}
		void Print() {
			cout << data;
		}
	};
public:
	typedef ListNode node_type;
	typedef _iterator<node_type> iterator;
	//constructors / destructors
	List();
	~List();
	//methods
	iterator begin();//Returns an iterator addressing the first element 
	iterator end();//Returns an iterator that addresses the location 
				   //succeeding the last element
	void clear();//Erases all the elements of a list.
	bool empty();//Tests if a list is empty.
	iterator find(const node_type & val);//Returns an iterator to the 
										 // first element in a list that 
										 //match a specified value.
	void pop_front();//Deletes the element at the beginning of a list.
	void push_front(const node_type val);//Adds an element to the beginning 
										 //of a list.
	void load(const char *filename); // ініціалізує список з csv - file
	void remove(const node_type val);//Erases first element in a list that 
									 //match a specified value.
	int size();//Returns the number of elements in a list.
	void splice(iterator _Where, List<T>& _Right);//Removes element from //the target list and inserts it in first
												  // position of the argument list.
	void	Print();//Dumps list into the screen
private:
	node_type *head;
	iterator *first, *last;
};

template <class T>
List<T>::List()
{
	head = NULL;
	first = NULL;
	last = NULL;
}
template <class T>
List<T>::~List()
{
	delete head;
	delete last;
	delete first;
}
template <class T>
void List<T>::pop_front()
{
	if (empty() != true)
	{
		remove(head->data);
	}
	else
	{
		cout << "Empty list"<<endl;
	}
}
template <class T>
void List<T>::push_front(const node_type val)
{
	node_type *p = new node_type(val.data);
	p->next = NULL;
	if (empty() == true)
	{
		head = p;
		first = new iterator();
		*first = p;
		last = new iterator();
		*last = p;
	}
	else
	{
		p->next = head;
		head = p;
		*first = p;
	}
}
template <class T>
void List<T>::remove(const node_type val)
{
	node_type *p = head;
	while (p != NULL)
	{
		if (p->data == val.data)
		{
			break;
		}
		p = p->next;
	}
	if (p != NULL)
	{
		if (head == p)
		{
			head = head->next;
			*first = head;
		}
		else
		{
			node_type *pk = head;
			while (pk->next != p)
			{
				pk = pk->next;
			}
			pk->next = p->next;
			if (*last == p)
			{
				*last = pk;
			}
		}
	}
}
template <class T>
int List<T>::size()
{
	node_type *p = head;
	int count = 0;
	while (p!=NULL)
	{
		count++;
		p = p->next;
	}
	delete[] p;
	return count;
}
template <class T>
void List<T>::clear()
{
	while (empty() != true)
	{
		pop_front();
	}
}
template <class T>
bool List<T>::empty()
{
	if (head == NULL) return true;
	else return false;
}
template <class T>
void List<T>::Print()
{
	iterator it = begin();
	while (it != end())
	{
		(*it).Print();
		it++;
	}
}
template <class T>
_iterator<typename List<T>::node_type> List<T>::begin()
{
	if (first != NULL) return *first; 
	return NULL;
}
template <class T>
_iterator<typename List<T>::node_type> List<T>::end()
{
	if (first!=NULL) return (**last).next;
	return NULL;
}
template <class T>
_iterator<typename List<T>::node_type> List<T>::find(const node_type & val)
{
	iterator it=begin();
	while (it != end())
	{
		if ((*it).data == val.data)
		{
			return it;
		}
		it++;
	}
	return NULL;
}

template <class T>
void List<T>::splice(iterator _Where, List<T>& _Right)
{
	if (_Where == NULL) return;
	iterator it = begin();
	while (it != end())
	{
		if (it ==_Where)
		{
			_Right.push_front(*it);
			if (it == begin())
			{
				pop_front();
			}
			else
			{
				iterator it2 = begin();
				while ((*(*it2).next).data != (*it).data)
				{
					it2++;
				}
				(*it2).next = (*it).next;
				if (it==*last)
				{
					*last = it2;
				}
			}
			break;
		}
		it++;
	}
}
template <class T>
void List<T>::load(const char *filename)
{
	ifstream f(filename);
	if (f.is_open())
	{
		while (!f.eof())
		{
			string buf;
			const int max_lenght = 1024;
			char str[max_lenght];
			f.getline(str, max_lenght);
			T tmp(str);
			push_front(tmp);
		}
		f.close();
	}
}