#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Student
{
public:
	Student(void);
	Student(string stuid,string name,string gender,string major,int age);
	string getName();
	void print();
	bool isValid();

public:
	~Student(void);
private:
	string _stuid;
	string _name;
	string _gender;
	string _major;
	int _age;
	int errortimes;
	int flag;
};
