#include <iostream>
using namespace std;

class MyString
{
	char* str;
	int length;
public:
	MyString();
	MyString(const char* obj);
	MyString(const MyString& obj);
	void Print();
	void Input();
	void MyStrcpy(MyString& obj);
	bool MyStrStr(const char* str);
	int  MyChr(char c);
	int MyStrLen();
	void MyStrCat(MyString& b);
	void MyDelChr(char c);
	int MyStrCmp(MyString& b);
	~MyString();
};

MyString::MyString()
{
	length = 80;
	str = new char[length];
}

MyString::MyString(const char* obj)
{
	length = strlen(obj);
	str = new char[length + 1];
	strcpy_s(str, length + 1, obj);
}

MyString::MyString(const MyString& obj)
{
	length = obj.length;
	str = new char[length + 1];
	strcpy_s(str, length + 1, obj.str);
}

void MyString::Print()
{
	cout << str << endl;
}

void MyString::Input()
{
	char buff[80];
	cout << "Input string: ";
	cin >> buff;
	if (str != nullptr)
	{
		delete[] str;
	}
	length = strlen(buff);
	str = new char[length + 1];
	strcpy_s(str, length + 1, buff);
}

void MyString::MyStrcpy(MyString& obj)
{
	if (str != nullptr)
	{
		delete[] str;
	}
	length = obj.length;
	str = new char[length + 1];
	strcpy_s(str, length + 1, obj.str);
}

bool MyString::MyStrStr(const char* str)
{
	bool found = false;
	char* foundstr = strstr((*this).str, str);
	if (foundstr != nullptr)
	{
		found = true;
	}
	return found;
}

int MyString::MyChr(char c)
{
	int index = -1;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == c)
		{
			index = i;
		}
	}
	return index;
}

int MyString::MyStrLen()
{
	return length;
}

void MyString::MyStrCat(MyString& b)
{
	char* buff = new char[length + 1];
	strcpy_s(buff, length + 1, str);
	delete[] str;
	str = new char[length + b.length + 1];
	strcpy_s(str, length + 1, buff);
	strcat_s(str, length + b.length + 1, b.str);
}

void MyString::MyDelChr(char c)
{
	int i = (*this).MyChr(c);
	if (i != -1)
	{
		char* buff = new char[length + 1];
		strcpy_s(buff, length + 1, str);
		delete[] str;
		str = new char[length];
		for (int j = 0, k = 0; j < length + 1; j++)
		{
			if (j != i)
			{
				str[k] = buff[j];
				k++;
			}
		}
	}
}

int MyString::MyStrCmp(MyString& b)
{
	if (length < b.length)
	{
		return -1;
	}
	else if (length > b.length)
	{
		return 1;
	}
	else {
		return 0;
	}
}

MyString::~MyString()
{
	delete[] str;
}

int main()
{
	MyString obj1("Hello");
	obj1.Print();
	cout << obj1.MyChr('e') << endl;


	MyString obj2(obj1);
	obj2.Print();

	obj2.Input();
	obj2.Print();
	cout << obj1.MyStrCmp(obj2) << endl;
	obj1.MyStrcpy(obj2);
	obj1.Print();

	MyString obj3("World");
	obj2.MyStrCat(obj3);
	obj2.Print();
	obj3.MyDelChr('o');
	obj3.Print();
	cout << obj3.MyStrStr("o") << endl;
}

