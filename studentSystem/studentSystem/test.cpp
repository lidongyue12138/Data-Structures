#include "Student.h"

using namespace std;
string stuid;
string name;
string gender;
string major;
int age;
char ch;
char choose;
vector<Student> stuVec;
int i=0;
int main()
{
	Student stu;
	cout <<"-----欢迎来到上海对外经贸大学学生管理系统-----"<< endl;
	while(true)
	{
		cout <<"请选择（0-录入信息，1-查找学生，2-删除学生，3-查看所有学生，q-退出）：";
		cin >> ch;
		switch (ch)
		{
		case '0':
			while(true)
			{
				cout << "请输入新学生的学号:";
				cin >> stuid;
				cout << "请输入新学生的姓名:";
				cin >> name;
				cout << "请输入新学生的性别:";
				cin >> gender;
				cout << "请输入新学生的年龄:";
				cin >> age;
				cout << "请输入新学生的专业:";
				cin >> major;
				Student stu(stuid,name,gender,major,age);
				stu.print();
				stuVec[i] = stu;
				i++;
				cout << "是否继续录入新学生的信息(y or n)?";
				cin >> choose;
				if(choose != 'y')
				{
					cout << "录入完毕！" << endl;
					break;
				}
			}
			break;
		case '1':

			break;
		case '2':
			break;
		case '3':
			for(int i=0;i<stuVec.size();i++)
			{
				stuVec[i].print();
			}
			break;
		case 'q':
			break;
		}
	}
	return 0;
}
