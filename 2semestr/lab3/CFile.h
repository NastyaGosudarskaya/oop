#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class CFile {
public:
	CFile & operator=(const CFile & ob);
	bool operator==(const CFile & ob);
	bool operator!=(const CFile & ob);
	CFile();
	CFile(char *fn, char *cd, int sz) : _filename(fn), _creation_date(cd), _size(sz) {}
	CFile(char *str);
	char* getfilename() { return _filename; }
	char* getdate() { return _creation_date;}
	void setfilename(const char *name);
	/*
	methods
	*/
	friend ostream& operator<<(ostream& stream, CFile &obj);
private:
	char *_filename;
	char *_creation_date;
	int _size;
};
