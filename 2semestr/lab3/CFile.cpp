#include "CFile.h"

ostream& operator<<(ostream& stream, CFile &obj)
{
	cout << "filename: " << obj._filename << " creation_date: " << obj._creation_date << " size: " << obj._size << endl;
	return stream;
}
CFile::CFile()
{
	_filename = NULL;
	_creation_date = NULL;
	_size = 0;
}
CFile & CFile::operator=(const CFile &ob)
{
	_filename = new char[strlen(ob._filename)+1];
	for (int i = 0; i<strlen(ob._filename); i++)
	{
		_filename[i] = ob._filename[i];
	}
	_filename[strlen(ob._filename)] = '\0';

	_creation_date = new char[strlen(ob._creation_date)+1];
	for (int i = 0; i<strlen(ob._creation_date); i++)
	{
		_creation_date[i] = ob._creation_date[i];
	}
	_creation_date[strlen(ob._creation_date)] = '\0';

	_size = ob._size;

	return *this;
}

bool CFile::operator==(const CFile & ob)
{
	return (strcmp(ob._filename, _filename) == 0 && strcmp(ob._creation_date, _creation_date) == 0 && _size == ob._size);
}

bool CFile::operator!=(const CFile & ob)
{
	return !(strcmp(ob._filename, _filename) == 0 && strcmp(ob._creation_date, _creation_date) == 0 && _size == ob._size);
}

CFile::CFile(char *str)
{
	char *buff = new char[50];
	int i = 0;
	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] == ';') break;
		buff[i] = str[i];

	}
	buff[i] = '\0';
	_filename = new char[strlen(buff)+1];
	for (int k = 0; k < strlen(buff); k++) _filename[k] = buff[k];
	_filename[strlen(buff)]='\0';
	delete[] buff;

    int j = 0;
	buff = new char[50];
	for (j = i + 1; j < strlen(str); j++)
	{
		if (str[j] == ';')
		{
			break;
		}
		buff[j-i-1] = str[j];
	}
	buff[j-i-1] = '\0';
	_creation_date = new char[strlen(buff)+1];
	for (int k = 0; k < strlen(buff); k++) _creation_date[k] = buff[k];
	_creation_date[strlen(buff)] = '\0';
	delete[] buff;

	buff = new char[50];
	for (i = j + 1; i < strlen(str); i++)
	{
		buff[i - j - 1] = str[i];
	}
	buff[i] = '\0';
	_size = atoi(buff);
	delete[] buff;
}


void CFile::setfilename(const char *name)
{
	if (_filename != NULL)
		delete[] _filename;
	_filename = new char[strlen(name)+1];
	for (int i = 0; i <  strlen(name); i++)
		_filename[i] = name[i];
	_filename[strlen(name)] = '\0';

}
