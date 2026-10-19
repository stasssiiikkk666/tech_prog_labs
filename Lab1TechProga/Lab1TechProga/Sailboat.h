#pragma once
#include <iostream>
#include <string>
#include "Base.h"
using namespace std;

class Sailboat: public Base{
private:
	string type;
	string name;
	string status; //мирный или военный
	double length;
public:
	Sailboat(double speed, int amount, string type, string name, string status, double length) : Base(speed, amount) {
		SetType(type);
		SetName(name);
		SetStatus(status);
		SetLength(length);
		cout << "Sailboat class Constructor with parameters was called." << endl;
	};
	Sailboat();
	~Sailboat();
	void SetType(string type);
	void SetName(string name);
	void SetStatus(string status);
	void SetLength(double length);


	string GetType() const;
	string GetName() const;
	string GetStatus() const;
	double GetLength() const;

	void CreateObject() override;
	void PrintInfo() const override;
	void EditInfo() override;
	//void DeleteObject() override;

};