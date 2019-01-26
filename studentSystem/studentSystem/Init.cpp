#include "Init.h"

Init::Init(void)
{
}

Init::~Init(void)
{
}


void Init::write(const std::string &filename, std::vector<Student> &vec)
{
	ofstream out(filename.c_str());

	//判断文件输出流对象是否存在

	//if(!out.is_open())
	if(!out)
	{
		cout<<"cannon open file to write!" << endl;
		return;
	}

	//写文件
	vector<Student>::iterator iter=vec.begin();

	for(;iter!=vec.end();iter++)
	{
		out<<iter->getStuid()<<"\t"<<iter->getName()
			<<"\t"<<iter->getGender()<<"\t"<<iter->getAge()
			<<"\t"<<iter->getMajor()<<endl;
	}


	out.close();
}

void Init::read(const std::string &filename,vector<Student>& stuVec)
{
	ifstream in(filename.c_str());

	if(!in)
	{
		cout<<"Error to open file to read！"<<endl;
		return;
	}
	string line;
	
	while(getline(in,line))
	{

		vector<string> vec=StringOp::split(line,"\t");

		if(vec.size()==5)
		{
			string id=vec[0];
			string name=vec[1];
			string gender=vec[2];
			int age=atoi(vec[3].c_str());
			string major=vec[4];

			Student stu(id,name,gender,age,major);
			stuVec.push_back(stu);

		}

	}
	

	in.close();

}