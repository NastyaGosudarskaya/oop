#include "Header.h"
using namespace std;
int main()
{
	cString s1;
	cString s2("cat");
    cString s3 = s2;
	if (s2.Isempty())
	{
		cout << "The object is empty" << endl;
	}
	else
	{
		cout << "The length of object is " << s2.Getlength() << endl;
	}
	s2.Empty();
	if (s2.Getlength() == 0)
	{
		cout << "The object is empty" << endl;
	}
	s1 = "String for set";
	s1.Print();
	s1.SetAt(5, 'i');
	s1.Print();
	s2 = "rini";
	s2.Print();
	if (s1.Compare(s2) == -1)
	{
		cout << "s1 < s2" << endl;
	}
	if (s1.Compare(s2) == 1)
	{
		cout << "s1 > s2" << endl;
	}
	if (s1.Compare(s2) == 0)
	{
		cout << "s1 == s2" << endl;
	}
	if (s1.Compare(s2) == 2)
	{
		cout << "s1 has the same length as s2" << endl;
	}
	s3 = s1.Mid(2, 4);
	s3.Print();
	if (s3.Compare(s2) == 0)
	{
		cout << "s1 includes s3" << endl;
	}
	s3 = s1.Left(4);
	s3.Print();
	s2 = "Stri";
	if (s3.Compare(s2) == 0)
	{
		cout << "s1 includes s3" << endl;
	}
	s3 = s1.Right(2);
	s3.Print();
	s2 = "et";
	if (s3.Compare(s2) == 0)
	{
		cout << "s1 includes s3" << endl;
	}
	char c = 'i';
	int i = s1.Find(c);
	if (i == -1) cout << "The symbol '" << c << "' isn't found" << endl;
	else cout << "The index of the first enterence of '" << c << "' is " << i << endl;
	i = s1.Find("ni");
	if (i == -1) cout << "The string isn't found" << endl;
	else cout << "The index of the first enterence of string is " << i << endl;

	//operators
	cString s("abc");
	if (s[1] == 'b') cout << "The function works right" << endl;

	cString ss1, ss3;
	ss1 = "dog";
	ss3 = ss1;
	ss1.Print();
	ss3.Print();

	cString ss("cat"), ss2;
	ss2 = ss;
	ss2.Print();
	ss.Print();

	cString ss6("ahjf"), ss7("kjo");
	(ss6 + ss7).Print();

	cString ss4("abc"), ss5("def");
	ss4 += ss5;
	ss4.Print();
	system("pause");
	return 0;
}
