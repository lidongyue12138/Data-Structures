#pragma once
#include <vector>
#include <string>

using namespace std;
class StringOp
{
public:
	StringOp(void);
	static vector<string> split(const string& str,const string& delim);
public:
	~StringOp(void);
};
