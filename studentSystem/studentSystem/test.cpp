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
	cout <<"-----��ӭ�����Ϻ����⾭ó��ѧѧ������ϵͳ-----"<< endl;
	while(true)
	{
		cout <<"��ѡ��0-¼����Ϣ��1-����ѧ����2-ɾ��ѧ����3-�鿴����ѧ����q-�˳�����";
		cin >> ch;
		switch (ch)
		{
		case '0':
			while(true)
			{
				cout << "��������ѧ����ѧ��:";
				cin >> stuid;
				cout << "��������ѧ��������:";
				cin >> name;
				cout << "��������ѧ�����Ա�:";
				cin >> gender;
				cout << "��������ѧ��������:";
				cin >> age;
				cout << "��������ѧ����רҵ:";
				cin >> major;
				Student stu(stuid,name,gender,major,age);
				stu.print();
				stuVec[i] = stu;
				i++;
				cout << "�Ƿ����¼����ѧ������Ϣ(y or n)?";
				cin >> choose;
				if(choose != 'y')
				{
					cout << "¼����ϣ�" << endl;
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
