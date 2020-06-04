#include "CTreeNode.h"
CTreeNode::CTreeNode()
{
	this->m_Trainnumber = 0;
	this->m_Destination = "";
	this->m_Departuretime = "";
	this->l = nullptr;
	this->r = nullptr;
}

string CTreeNode::getdepart()
{
	return this->m_Departuretime;
}
string CTreeNode::getdest()
{
	return this->m_Destination;
}
int CTreeNode::getnum()
{
	return this->m_Trainnumber;
}
CTreeNode* CTreeNode::getl()
{
	return this->l;
}
CTreeNode* CTreeNode::getr()
{
	return this->r;
}

void CTreeNode::setdepart(string depart)
{
	this->m_Departuretime = depart;
}
void CTreeNode::setdest(string dest)
{
	this->m_Destination = dest;
}
void CTreeNode::setnum(int num)
{
	this->m_Trainnumber = num;
}
void CTreeNode::setr(CTreeNode *right)
{
	this->r = right;
}
void CTreeNode::setl(CTreeNode *left)
{
	this->l = left;
}

void CTreeNode::printnode()
{
	cout << this->m_Trainnumber << ";" << this->m_Destination << ";" << this->m_Departuretime<<endl;
}