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
	double speed;
	int amountCrew;
public:
	Sailboat(string type, string name, string status, double length, double speed, int amountCrew) :
		type{ type }, name{ name }, status{ status }, length{ length }, speed{ speed }, amountCrew{ amountCrew }{
		cout << "Sailboat class Constructor with parameters was called." << endl;
	}
	Sailboat();
	~Sailboat();
	void SetType(string type);
	void SetName(string name);
	void SetStatus(string status);
	void SetLength(double length);
	void SetSpeed(double speed);
	void SetAmountCrew(int amountCrew);

	string GetType() const;
	string GetName() const;
	string GetStatus() const;
	double GetLength() const;
	double GetSpeed() const;
	int GetAmountCrew() const;

	void PrintInfo() const override;
	void EditInfo() override;
	void DeleteObject() override;
};