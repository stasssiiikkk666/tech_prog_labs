#pragma once
#include <iostream>
#include <string>
using namespace std;

class Base {

public: 
	virtual void PrintInfo() const = 0;
	virtual void EditInfo() = 0;
	virtual void DeleteObject() = 0;
	Base();
	virtual ~Base();
};