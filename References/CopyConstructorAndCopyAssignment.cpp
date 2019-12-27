// TestCppClasses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string.h>
using namespace std;
class test
{
private:
	int _id;
	char* _name;
	char _school[20];

public:
	test(int id, const char* name, const char* school) :_id(id)
	{
		_name = new char[strlen(name)];
		strcpy(_name, name);
		cout << "After Copy in constructor" << endl;
		strcpy(_school, school);
	}

	test(const test& rhs)
	{
		if (this != &rhs)
		{
			this->_id = rhs._id;
			_name = new char[strlen(rhs._name)];
			strcpy(_name, rhs._name);
			strcpy(_school, rhs._school);
		}
	}
	test& operator=(const test& rhs)
	{
		if (this == &rhs)
			return *this;

		this->_id = rhs._id;
		//delete this->_name;
		char* pOrigName = _name;
		_name = new char[strlen(rhs._name)];
		strcpy(_name, rhs._name);
		strcpy(_school, rhs._school);
		delete pOrigName;
		return *this;
	}

	void display()
	{
		std::cout << "ID  :" << _id << std::endl;
		std::cout << "NAME:" << _name << std::endl;
		std::cout << "SCHOOL:" << _school << std::endl;
	}

	~test()
	{
		delete _name;
	}
};

int main()
{
	std::cout << "Hello World!\n";
	test Akshay(1, "Akshay", "LBHS");
	Akshay.display();
	std::cout << "Coping " << std::endl;
	test tmp(Akshay);
	tmp.display();
	test a2(2, "abcd", "xyz");
	a2.display();
	cout << "------" << endl;
	a2 = tmp;
	a2.display();
}
