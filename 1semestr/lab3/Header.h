#pragma once
#ifndef CSTRING_H_INCLUDED
#define CSTRING_H_INCLUDED
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
using namespace std;
class cString {
public:
	//constructors/destructor
	cString();
	cString(const char *psz);
	cString(const cString& stringsrc);
	~cString();
	//methods
	int Getlength() const;
	bool Isempty()const;
	void Empty();
	void SetAt(int nindex, char ch);
	int Compare(const cString &s) const;
	int Find(char ch) const;
	int Find(char *pszsub) const;
	cString Mid(int nfirst, int ncount) const;
	cString Left(int ncount) const;
	cString Right(int ncount) const;
	void Print();
	cString& operator =(const cString& stringsrc);
	const cString operator =(const  char* psz);
	char operator [](int indx);
	cString operator +(const cString& string);
	cString& operator +=(const cString& string);
private:
	char *str;
};
#endif // CSTRING_H_INCLUDED