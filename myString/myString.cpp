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
	cout << "Input sting: ";
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

int MyString::MyStrLen()
{
	return length;
}

int MyString::MyStrCmp(MyString& b)
{
	if ((*this).length < b.length)
	{
		return -1;
	}
	else if ((*this).length > b.length)
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

	MyString obj2(obj1);
	obj2.Print();

	obj2.Input();
	obj2.Print();
	cout << obj1.MyStrCmp(obj2) << endl;
	obj1.MyStrcpy(obj2);
	obj1.Print();
}

