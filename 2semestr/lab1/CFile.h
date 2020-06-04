#pragma once
#ifndef CFILE_H_INCLUDED
#define CFILE_H_INCLUDED
#include <cstring>
#include <iostream>
class CFile {
public:
	//default constructor
	CFile();
	//copy constructor
	CFile(const CFile &);
	//destructor
	~CFile();
	void SetDetails(const char *, int);
	void SetKeywords(const char*);
	//overloaded assignment
	CFile & operator=(const CFile &);
	bool operator<(const CFile &)const;
	int GetSize()const { return size; };
	char *Getname()const { return name; }
	int GetKeywords_nmb()const { return keywords_nmb; };
	char *Getkeywords()const { return keywords; }
	void SetSize(int);
	void Print()const;

private:
	char *name;//file name
	int size;//file length
	char *keywords;//set of keywords
	int keywords_nmb;//keywords number
};


#endif // CFILE_H_INCLUDED