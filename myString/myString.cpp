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
}

