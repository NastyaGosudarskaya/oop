#include "CFile.h"
#include <vector>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>


using namespace std;

void ListAll(const vector<CFile> &);//Вивести на консоль уміст контейнера
void AddKeyword(vector<CFile> &, char *);//Додати у файли ключове слово
void DelKeyword(vector<CFile> &, char *kwrd);//Вилучити з файлів ключове слово kwrd.
void DelKeywordByLen(vector <CFile> &, int len);//Вилучити з файлів ключові слова, довжини більше len.
void SortBySize(vector<CFile> &);//Відсортувати елементи контейнера в лексикографічному порядку імен файлів.
void SortByKeywordsNumber(vector<CFile> &);//Відсортувати елементи контейнера в порядку неубування числа ключових слів

int main()
{
	ifstream file("input.csv");
	CFile tmp;
	int size;
	char name[256];
	char keywords[256];
	vector<CFile> v;

	while (!file.eof())
	{
		file.getline(name, 256, ';');
		file >> size;
		file.get();
		file.getline(keywords, 256);
		tmp.SetDetails(name, size);
		tmp.SetKeywords(keywords);
		v.push_back(tmp);
	}
	file.close();
	ListAll(v);
	cout << "After adding a keyword:" << endl;
	AddKeyword(v, "university");
	ListAll(v);
	cout << "After deleting a keyword:" << endl;
	DelKeyword(v, "is");
	ListAll(v);
	cout << "After deleting a keyword with the lenghts more than 4:" << endl;
	DelKeywordByLen(v,4);
	ListAll(v);
	cout << "After sorting by keyword numbers:" << endl;
	SortByKeywordsNumber(v);
	ListAll(v);
	cout << "After sorting by size:" << endl;
	SortBySize(v);
	ListAll(v);
	system("pause");
}

void ListAll(const vector<CFile> &v)
{
	for(int i=0; i<v.size();i++)
	{
		v.at(i).Print();
	}
}

void AddKeyword(vector<CFile> &v, char *str)
{
	if (str == NULL)
	{
		return;
	}
	for (int i=0; i<v.size(); i++)
	{
		char *buff = new char[strlen(v.at(i).Getkeywords()) + strlen(str) + 2];
		for (int j = 0; j <strlen(v.at(i).Getkeywords()); j++)
		{
			buff[j] = (v.at(i).Getkeywords())[j];
		}
		buff[strlen(v.at(i).Getkeywords())] = ';';
		for (int j = 0; j < strlen(str); j++)
		{
			buff[strlen(v.at(i).Getkeywords()) + j + 1] = str[j];
		}
		buff[strlen(v.at(i).Getkeywords()) + strlen(str) + 1] = '\0';
		v.at(i).SetKeywords(buff);
		delete[]buff;
	}
}
void DelKeyword(vector<CFile> &v, char *kwrd)
{
	if (kwrd == NULL)
	{
		return;
	}
	for (int i = 0; i < v.size();i++) 
	{
		for (int k = 0; k < strlen(v[i].Getkeywords()); k++)
		{
			if ((v.at(i).Getkeywords())[k] == kwrd[0])
			{
				int counter = 1;
				for (int j = 1; j < strlen(kwrd); j++)
				{
					if ((v.at(i).Getkeywords())[k + j] != kwrd[j])
					{
						break;
					}
					else
					{
						counter++;
					}
				}
				int flag = 0;
				if ((k != 0 && ((v.at(i).Getkeywords())[k - 1] == ';' && (v.at(i).Getkeywords())[k + counter] == ';')) || (k != 0 && ((v[i].Getkeywords())[k - 1] == ';' && (v[i].Getkeywords())[k + counter] == '\0')))
				{
					flag = 1;
				}
				else if (((k == 0) && ((v.at(i).Getkeywords())[k + counter] == ';'))||((k == 0) && ((v.at(i).Getkeywords())[k + counter] == '\0')))
				{
					flag = 1;
				}
				if (counter == strlen(kwrd)&&flag==1)
				{
					if (strlen(v.at(i).Getkeywords()) - counter > 0)
					{
						char *buff = new char[strlen(v.at(i).Getkeywords()) - counter];
						for (int j = 0; j<k - 1; j++)
						{
							buff[j] = (v.at(i).Getkeywords())[j];
						}
						if (k != 0)
						{
							for (int j = k + counter; j<strlen(v.at(i).Getkeywords()); j++)
							{
								buff[j - 1 - counter] = (v.at(i).Getkeywords())[j];
							}
						}
						else
						{
							for (int j = k + counter + 1; j<strlen(v.at(i).Getkeywords()); j++)
							{
								buff[j - counter - 1] = (v.at(i).Getkeywords())[j];
							}
						}
						buff[strlen(v.at(i).Getkeywords()) - counter - 1] = '\0';
						delete[]v.at(i).Getkeywords();
						v.at(i).SetKeywords(buff);
						delete[]buff;
					}
					else
					{
						v.at(i).SetKeywords("");
					}
				}
			}
		}
	}
}
void DelKeywordByLen(vector <CFile> &v, int len)
{
	for(int i=0; i<v.size();i++)
	{
	int counter = 0;
	for (int j = 0; j <= strlen(v[i].Getkeywords()); j++)
	{
		if (((v[i].Getkeywords())[j] == ';')||(((v[i].Getkeywords())[j] == '\0')))
		{
			if (counter > len)
			{
				char *buff=new char[counter+1];
				for (int k = 0; k < counter; k++)
				{
					buff[k] = (v[i].Getkeywords())[j-counter+k];
				}
				buff[counter] = '\0';
				DelKeyword(v, buff);
				j = -1;
				delete[]buff;
			}
			counter = 0;
		}
		else
		{
			counter++;
		}
	}
	}
}
void SortBySize(vector<CFile> &v)
{
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			if (strcmp(v.at(i).Getname(), v.at(j).Getname()) > 0)
			{
				CFile tmp(v[i]);
				v[i] = v[j];
				v[j] = tmp;
			}
		}
	}
}

void SortByKeywordsNumber(vector<CFile> &v)
{
	for (int j = 0; j < v.size()-1; j++)
	{
		for (int i = 0; i < v.size()-1-j; i++)
		{
			if (v.at(i).GetKeywords_nmb() > v.at(i + 1).GetKeywords_nmb())
			{
				CFile tmp(v[i]);
				v[i] = v[i + 1];
				v[i + 1] = tmp;
			}
		}
	}
}