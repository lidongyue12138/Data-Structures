#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "Student.h"
#include "StringOp.h"

using namespace std;
class Init
{
public:
	Init(void);
	void write(const string& filename,vector<Student>& vec);
	void read(const string& filename,vector<Student>& vec);
public:
	~Init(void);
};
