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
	cout << "ѧ�ţ�"<<_stuid<<"��������"<<_name<<"���Ա�"
		<<_gender<<"�����䣺"<<_age<<"��רҵ��"<<_major<<endl;

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
			cout << "��¼�ɹ�����" << endl;
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
