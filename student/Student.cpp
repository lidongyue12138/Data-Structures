#include "Student.h"

Student::Student(void)
{
}
Student::Student(string stuid, string name, string gender, string major, int age)
{
	_stuid = stuid;
	_name = name;
	_gender = gender;
	_age = age;
	_major = major;
}

void Student::print()
{
	cout << "学号："<<_stuid<<"，姓名："<<_name<<"，性别："
		<<_gender<<"，年龄："<<_age<<"，专业："<<_major<<endl;

}
string Student::getName()
{
	return _name;
}
bool Student::isValid()
{
	vector<Student>::iterator iter = vector<Student>.begin();

	for (;iter!=vec.end(); i++)
	{
		if (_stuid ==  && inputPassword == password[i])
		{
			cout << "登录成功！！" << endl;
			exit(-1);
		}
		else
		{
			if (i == 4)
			{
				flag = 1;
			}
			continue;
		}
	}
}
Student::~Student(void)
{
}
