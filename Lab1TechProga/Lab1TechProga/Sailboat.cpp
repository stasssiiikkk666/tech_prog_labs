#include <iostream>
#include <string>
#include "Sailboat.h"
#include "Exceptions.h"
using namespace std;


Sailboat::Sailboat()
{
	this->type = "-";
	this->name = "-";
	this->status = "-";
	this->length = 0.0;
	cout << "Sailboat class Default Constructor was called." << endl;
}

Sailboat::~Sailboat()
{
	cout << "Sailboat class Destructor was called." << endl;
}

void Sailboat::SetType(string type) {
	if (type == "") throw Exceptions{ "Please, enter type of Sailboat." };
	this->type = type;

}

void Sailboat::SetName(string name) { 
	if (name == "")
		throw Exceptions{ "Please, enter name of Sailboat." };
	this->name = name;
}

void Sailboat::SetStatus(string status) {
	if ((status != "civilian" && status != "military") || status == "")
		throw Exceptions{ "Please, enter status (civilian/military) of Sailboat." };
	this->status = status;
}

void Sailboat::SetLength(double length){
	if (length < 0) throw Exceptions{ "Please, enter length >=0 of Sailboat." };
	this->length = length;
}

string Sailboat::GetType() const { return type; }
string Sailboat::GetName() const { return name; }
string Sailboat::GetStatus() const { return status; }
double Sailboat::GetLength() const { return length; }


void Sailboat::CreateObject()
{
	bool success = false;
	do {
		string type;
		cout << "\nEnter new type: ";
		cin.ignore();
		getline(cin, type);
		try { SetType(type); success = true; }
		catch (const Exceptions& ex) {
			cout << ex.GetMessage() << endl;
		}
	} while (success == false);

	do {
		success = false;
		string name;
		cout << "\nEnter new Name: ";
		getline(cin, name);
		try { SetName(name); success = true; }
		catch (const Exceptions& ex) {
			cout << ex.GetMessage() << endl;
		}
	} while (success == false);
	
	do {
		success = false;
		string status;
		cout << "\nEnter new Status: ";
		getline(cin, status);
		try { SetStatus(status); success = true; }
		catch (const Exceptions& ex) {
			cout << ex.GetMessage() << endl;
		}
	} while (success == false);
	
	do {
		success = false;
		double length;
		cout << "\nEnter new Length: ";
		cin >> length;
		try { 
			ValidData(cin.fail());
			SetLength(length); 
			success = true; 
		}
		catch (const Exceptions& ex) {
			cout << ex.GetMessage() << endl;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			cin.get();
		}
	} while (success == false);
	
	do {
		success = false;
		double speed;
		cout << "\nEnter new Speed: ";
		cin >> speed;
		try { 
			ValidData(cin.fail());
			SetSpeed(speed);
			success = true; 
		}
		catch (const Exceptions& ex) {
			cout << ex.GetMessage() << endl;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			cin.get();
		}
	} while (success == false);
	
	do {
		success = false;
		int amount;
		cout << "\nEnter new Amount of crew: " << endl;
		cin >> amount;
		
		try {
			ValidData(cin.fail());
			SetAmountCrew(amount); 
			success = true; }
		catch (const Exceptions& ex) {
			cout << ex.GetMessage() << endl;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			cin.get();
		}
	} while (success == false);
	
}

void Sailboat::PrintInfo() const
{
	cout << "ID: " << this->GetID() << endl;
	cout << "Type: " << this->GetType() << endl;
	cout << "Name: " << this->GetName() << endl;
	cout << "Status: " << this->GetStatus() << endl;
	cout << "Length: " << this->GetLength() << endl;
	cout << "Speed: " << this->GetSpeed() << endl;
	cout << "Amount of crew: " << this->GetAmountCrew() << endl;
}

void Sailboat::EditInfo()
{
	int choice;
	double editParam1;
	string editParam2;
	int amount;
	cout << "[1] Edit Type" << endl;
	cout << "[2] Edit Name" << endl;
	cout << "[3] Edit Status" << endl;
	cout << "[4] Edit Length" << endl;
	cout << "[5] Edit Speed" << endl;
	cout << "[6] Edit Amount of crew" << endl;
	cout << "\nEnter your choice: " << endl;
	cin >> choice;
	switch (choice) {
	case 1: 
		cout << "Enter new type: ";
		getline(cin, editParam2);
		SetType(editParam2);
		break;
	case 2:
		cout << "Enter new Name: ";
		getline(cin, editParam2);
		SetName(editParam2);
		break;
	case 3:
		cout << "Enter new Status: ";
		getline(cin, editParam2);
		SetStatus(editParam2);
		break;
	case 4:
		cout << "Enter new Length: ";
		cin >> editParam1;
		SetLength(editParam1);
		break;
	case 5:
		cout << "Enter new Speed: ";
		cin >> editParam1;
		SetSpeed(editParam1);
		break;
	case 6:
		cout << "Enter new Amount of crew: " << endl;
		cin >> amount;
		SetAmountCrew(amount);
		break;
	}

}

//void Sailboat::DeleteObject()
//{
//	delete this;
//}




