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
	if (type != "Sloop" && type != "Schooner" && type != "Brig" && type != "Barque" && type != "Racing yacht") throw
		Exceptions{ "Type of the Sailboat must be one of Sloop/Schooner/Brig/Barque/Racing yacht" };
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
	string param;
	bool success = false;
	do {
		try { 
			cout << "\nEnter new type: ";
			getline(cin, type);
			SetType(type);
			success = true; }
		catch (const Exceptions& ex) {
			cout << ex.GetMessage() << endl;
		}
	} while (success == false);

	do {
		success = false;
		try { 
			cout << "\nEnter new Name: ";
			getline(cin, name);
			SetName(name); 
			success = true; }
		catch (const Exceptions& ex) {
			cout << ex.GetMessage() << endl;
		}
	} while (success == false);
	
	do {
		success = false;
		try {
			cout << "\nEnter new Status: ";
			getline(cin, status);
			SetStatus(status); 
			success = true; }
		catch (const Exceptions& ex) {
			cout << ex.GetMessage() << endl;
		}
	} while (success == false);
	
	do {
		success = false;
		cout << "\nEnter new Length: ";
		getline(cin, param);
		try { 
			ValidData(param);
			SetLength(stod(param)); 
			success = true; 
		}
		catch (const Exceptions& ex) {
			cout << ex.GetMessage() << endl;
		}
	} while (success == false);
	
	do {
		success = false;
		cout << "\nEnter new Speed: ";
		getline(cin, param);
		try { 
			ValidData(param);
			SetSpeed(stod(param));
			success = true; 
		}
		catch (const Exceptions& ex) {
			cout << ex.GetMessage() << endl;
		}
	} while (success == false);
	
	do {
		success = false;
		cout << "\nEnter new Amount of crew: ";
		getline(cin, param);
		try {
			ValidIntData(param);
			SetAmountCrew(stoi(param)); 
			success = true; }
		catch (const Exceptions& ex) {
			cout << ex.GetMessage() << endl;
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
	string choice;
	string editParam;
	system("cls");
	cout << "--- Edit Menu ---" << endl;
	cout << "[1] Edit Type" << endl;
	cout << "[2] Edit Name" << endl;
	cout << "[3] Edit Status" << endl;
	cout << "[4] Edit Length" << endl;
	cout << "[5] Edit Speed" << endl;
	cout << "[6] Edit Amount of crew" << endl;
	cout << "[7] Print current object" << endl;
	cout << "[0] Back" << endl;
	cout << "\nEnter your choice: ";
	getline(std::cin, choice);
	std::cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	
	try {
		do {
			ValidIntData(choice);
			switch (stoi(choice)) {

			case 1:
				cout << "Enter new Type: ";
				getline(std::cin, editParam);
				try {
					SetType(editParam);
					cout << "Parameter was successfully edited." << endl;
				}
				catch (const Exceptions& ex) {
					cout << ex.GetMessage() << endl;
				}
				break;
			case 2:
				cout << "Enter new Name: ";
				getline(std::cin, editParam);
				try {
					SetName(editParam);
					cout << "Parameter was successfully edited." << endl;
				}
				catch (const Exceptions& ex) {
					cout << ex.GetMessage() << endl;
				}
				break;
			case 3:
				cout << "Enter new Status: ";
				getline(std::cin, editParam);
				try {
					SetStatus(editParam);
					cout << "Parameter was successfully edited." << endl;
				}
				catch (const Exceptions& ex) {
					cout << ex.GetMessage() << endl;
				}
				break;
			case 4:
				cout << "Enter new Length: ";
				getline(std::cin, editParam);
				try {
					ValidData(editParam);
					SetLength(stod(editParam));
					cout << "Parameter was successfully edited." << endl;
				}
				catch (const Exceptions& ex) {
					cout << ex.GetMessage() << endl;
				}
				break;
			case 5:
				cout << "Enter new Speed: ";
				getline(std::cin, editParam);
				try {
					ValidData(editParam);
					SetSpeed(stod(editParam));
					cout << "Parameter was successfully edited." << endl;
				}
				catch (const Exceptions& ex) {
					cout << ex.GetMessage() << endl;
				}
				break;
			case 6:
				cout << "Enter new Amount of crew: ";
				getline(std::cin, editParam);
				try {
					ValidIntData(editParam);
					SetAmountCrew(stoi(editParam));
					cout << "Parameter was successfully edited." << endl;
				}
				catch (const Exceptions& ex) {
					cout << ex.GetMessage() << endl;
				}
				break;
			case 7:
				this->PrintInfo();
				break;
			default:
				cout << "Invalid input! Please, enter 1/2/3/4/5/6/7/8 (0 - exit) number.";
				break;
			}
			std::cin.ignore();
			std::cin.get();
		} while (stoi(choice) != 0);
	} 
	catch (const Exceptions& ex) { cout << ex.GetMessage() << endl; }
}




