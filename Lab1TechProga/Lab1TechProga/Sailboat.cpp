#include <iostream>
#include <string>
#include "Sailboat.h"
using namespace std;

Sailboat::Sailboat()
{
}

Sailboat::~Sailboat()
{
}

void Sailboat::SetType(string type) {
	while (type == "") {
		cout << "Please, enter type of Sailboat";
		cin >> type;
	}
	this->type = type; 
}

void Sailboat::SetName(string name) { 
	while (name == "") {
		cout << "Please, enter name of Sailboat";
		cin >> name;
	}
	this->name = name;
}

void Sailboat::SetStatus(string status) {
	while (status == "") {
		cout << "Please, enter status (civillian/military) of Sailboat";
		cin >> status;
	}
	this->status = status;
}

void Sailboat::SetLength(double length){
	while (length == 0) {
		cout << "Please, enter length of Sailboat";
		cin >> length;
	}
	this->length = length;
}

void Sailboat::SetSpeed(double speed) {
	while (speed == 0) {
		cout << "Please, enter speed of Sailboat";
		cin >> speed;
	}
	this->speed = speed;
}

void Sailboat::SetAmountCrew(int amountCrew) {
	while (amountCrew == 0) {
		cout << "Please, enter name of Sailboat";
		cin >> amountCrew;
	}
	this->amountCrew = amountCrew;
}

string Sailboat::GetType() const { return type; }
string Sailboat::GetName() const { return name; }
string Sailboat::GetStatus() const { return status; }
double Sailboat::GetLength() const { return length; }
double Sailboat::GetSpeed() const { return speed; }
int Sailboat::GetAmountCrew() const { return amountCrew; }

void Sailboat::PrintInfo() const
{
}

void Sailboat::EditInfo()
{
}

void Sailboat::DeleteObject()
{
}









