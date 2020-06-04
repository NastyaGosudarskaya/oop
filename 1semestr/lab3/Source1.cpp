#include "Header.h"
//construcnors
cString::cString()
{
	this->str = NULL;
}
cString::cString(const char *psz)
{
	this->str = new char [strlen(psz)+1];
	int i;
	for (i = 0; i < strlen(psz); i++)
	{
		this->str[i] = psz[i];
	}
	this->str[i] = '\0';
}
cString::cString(const cString& stringsrc):str(new char [strlen(stringsrc.str)+1])
{
		int i = 0;
		for (i = 0; i < strlen(stringsrc.str); i++)
		{
			this->str[i] = stringsrc.str[i];
		}
		this->str[i] = '\0';
}
//destructor
cString :: ~cString()
{
	delete [] this->str;
}
//methods
int cString::Getlength() const
{
	int n = strlen(this->str);
	return n;
}
bool cString::Isempty()const
{
	if (this->Getlength() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void cString::Empty()
{
	delete [] this->str;
	this->str = new char[1];
	this->str[0] = '\0';
}
void cString::SetAt(int nindex, char ch)
{
	if ((nindex >= 0) && (nindex < this->Getlength()) && (ch != '\0'))
	{
		this->str[nindex] = ch;
	}
	else return;
}

int cString::Compare(const cString &s) const
{
	if (strcmp(this->str, s.str) == 0) return 0;
	if (this->Getlength() == s.Getlength()) return 2;
	if (this->Getlength() < s.Getlength()) return -1;
	if (this->Getlength() > s.Getlength()) return 1;
}

cString cString::Mid(int nfirst, int ncount) const
{
	cString s;
	s.str = new char[ncount + 1];
	int j = nfirst;
	int i = 0;
	for (i = 0; i<ncount; i++)
	{
		s.str[i] = this->str[j];
		j++;
	}
	s.str[i] = '\0';
	return s;
}

cString cString::Left(int ncount) const
{
	cString s;
	s.str = new char[ncount + 1];
	int j = 0;
	int i = 0;
	for (i = 0; i<ncount; i++)
	{
		s.str[i] = this->str[j];
		j++;
	}
	s.str[i] = '\0';
	return s;
}

cString cString::Right(int ncount) const
{
	cString s;
	s.str = new char[ncount + 1];
	int j = strlen(this->str) - ncount;
	int i = 0;
	for (i = 0; i<ncount; i++)
	{
		s.str[i] = this->str[j];
		j++;
	}
	s.str[i] = '\0';
	return s;
}

int cString::Find(char ch) const
{
	int i;
	for (i = 0; i<strlen(this->str); i++)
	{
		if (this->str[i] == ch) break;
	}
	if (i == strlen(this->str)) return -1;
	return i;
}

int cString::Find(char *pszsub) const
{
	int i;
	for (i = 0; i<strlen(this->str); i++)
	{
		int j = 0;
		if (this->str[i] == pszsub[j])
		{
			for (j = 0; j<strlen(pszsub); j++)
			{
				if (pszsub[j] != str[i + j]) break;
			}
		}
		if (j == strlen(pszsub)) break;
	}
	if (i == strlen(this->str)) return -1;
	return i;
}

void cString::Print()
{
	cout << this->str << endl;
}
//operators
char cString :: operator [](int indx)
{
	return this->str[indx];
}
const cString cString :: operator =(const char* psz)
{
	delete[] this->str;
	this->str = new char [strlen(psz)+1];
	int i=0;
	for (i = 0; i < strlen(psz); i++)
	{
		this->str[i] = psz[i];
	}
	this->str[i] = '\0';
	return *this;
}
cString& cString :: operator =(const cString& stringsrc)
{
	if (this != &stringsrc)
	{
		delete[] this->str;
		this->str = new char[strlen(stringsrc.str) + 1];
		int i=0;
		for (i = 0; i < strlen(stringsrc.str); i++)
		{
			this->str[i] = stringsrc.str[i];
		}
		this->str[i] = '\0';
	}
	return *this;
}

cString cString :: operator +(const cString& string)
{
	cString s;
	s.str = new char [strlen(this->str) + strlen(string.str)+1];
	int i = 0;
	for (i = 0; i < strlen(this->str);i++)
	{
		s.str[i]=this->str[i];
	}
	int j;
	for (j = 0; j < strlen(string.str); j++)
	{
		s.str[i] = string.str[j];
		i++;
	}
	s.str[i] = '\0';
	return s;
}

cString& cString ::  operator +=(const cString& string)
{
	char *buff=new char[strlen(this->str)+1];
	int i = 0;
	for (i = 0; i < strlen(this->str); i++)
	{
		buff[i] = this->str[i];
	}
	buff[i] = '\0';
	delete[] this->str;
	this->str = new char [strlen(buff)+strlen(string.str)+1];
	for (i = 0; i < strlen(buff); i++)
	{
		this->str[i] = buff[i];
	}
	delete[] buff;
	int j=0;
	for (j = 0; j < strlen(string.str); j++)
	{
		this->str[i] = string.str[j];
		i++;
	}
	this->str[i] = '\0';
	return *this;
}