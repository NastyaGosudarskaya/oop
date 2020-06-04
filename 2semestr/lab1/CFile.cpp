#include "CFile.h"
using namespace std;
CFile::CFile()
{
	name = nullptr;
	size = 0;
	keywords = nullptr;
	keywords_nmb = 0;
}
CFile::CFile(const CFile &obj)
{
	keywords_nmb = 0;
	this->SetDetails(obj.name, obj.size);
	this->SetKeywords(obj.keywords);
}
CFile::~CFile()
{
	delete[]name;
	delete[]keywords;
}
void CFile::SetDetails(const char *nam, int sz)//Initializing name and size
{
	if (sz < 0) return;
	if (nam == nullptr) return;
	int n = strlen(nam);
	name = new char[n+1];
	for (int i = 0; i<n; i++)
	{
		name[i] = nam[i];
	}
	name[n] = '\0';
	this->SetSize(sz);
}
void CFile::SetKeywords(const char *key)
{
	if (key == NULL)
	{
		return;
	}
	int n = strlen(key);
	keywords = new char[n+1];
	for (int i = 0; i<n; i++)
	{
		keywords[i] = key[i];
	}
	keywords[n] = '\0';
	keywords_nmb = 0;
	if (strlen(keywords) != 0)
	{
		for (int i = 0; i<n; i++)
		{
			if (keywords[i] == ';')
			{
				keywords_nmb++;
			}
		}
		keywords_nmb++;
	}
}
CFile& CFile::operator=(const CFile &ob)
{
	delete[]name;
	this->SetDetails(ob.name, ob.size);
	delete[]keywords;
	keywords_nmb = 0;
	this->SetKeywords(ob.keywords);
	return *this;
}
bool CFile::operator<(const CFile &v)const
{
	return this->size < v.size;
}
void CFile::SetSize(int sz)
{
	size = sz;
}
void CFile::Print()const
{
	if (name != nullptr)
	{
		cout << "name=" << name << endl;
	}
	else
	{
		cout << "name=Nope" << endl;
	}
	cout << "size=" << size << endl;
	if (keywords != nullptr)
	{
		cout << "keywords=" << keywords << endl;
	}
	else
	{
		cout << "keywords=Nope"<< endl;
	}
	cout << "keywords_nmb=" << keywords_nmb << endl;
	cout << endl;
}