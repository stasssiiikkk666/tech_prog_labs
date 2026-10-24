#include "Submarine.h"
#include "Exceptions.h"
#include <limits>
#include <sstream>
#include <string>
using namespace std;

Submarine::Submarine()
{
	this->length = 0;
	this->width = 0;
	this->armament = "None";
	this->timeUnderWater = 0;
	cout << "Submarine class Default Constructor was called." << endl;
}

Submarine::~Submarine(){ cout << "Submarine class Destructor was called." << endl; }

void Submarine::SetLength(double length) {
	if (length < 0) throw Exceptions{ "Length must be >= 0!" };
	this->length = length;
}

void Submarine::SetWidth(double width) {
	if (width < 0) throw Exceptions{ "Width must be >= 0!" };
	this->width = width;
}

void Submarine::SetTimeUnderWater(int timeUnderWater) {
	if (timeUnderWater < 0) throw Exceptions{ "Time must be >= 0!" };
	this->timeUnderWater = timeUnderWater;
}

void Submarine::SetArmament(string armament) {
	if (armament == "") throw Exceptions{ "Please, enter type of the Armament Sailboat." };
	if (armament != "Torpedoes" && armament != "Missiles" && armament != "Mixed" && armament != "Mines"
		&& armament != "None") throw Exceptions{ 
			"The Submarine's Armament must be one of Torpedoes/Missiles/Mixed/Mines/None" };
	this->armament = armament;
}

double Submarine::GetLength() const { return length; }
double Submarine::GetWidth() const { return width; }
int Submarine::GetTimeUnderWater() const { return timeUnderWater; }
string Submarine::GetArmament() const { return armament; }

void Submarine::CreateObject()
{
	string param;
	bool success = false;
	do {
		std::cout << "\nEnter new Length: ";
		getline(std::cin, param);
		try {
			ValidData(param);
			SetLength(stod(param));
			success = true;
		}
		catch (const Exceptions& ex) {
			std::cout << ex.GetMessage() << endl;
		}
	} while (success == false);

	do {
		success = false;
		std::cout << "\nEnter new Width: ";
		getline(std::cin, param);
		try {
			ValidData(param);
			SetWidth(stod(param));
			success = true;
		}
		catch (const Exceptions& ex) {
			cout << ex.GetMessage() << endl;
		}
	} while (success == false);

	do {
		success = false;
		cout << "\nEnter new Armament: ";
		getline(cin, param);
		try {
			SetArmament(DeleteSpaces(param));
			success = true;
		}
		catch (const Exceptions& ex) {
			cout << ex.GetMessage() << endl;
		}
	} while (success == false);

	do {
		success = false;
		cout << "\nEnter new Time under the water: ";
		getline(cin, param);
		try {
			ValidIntData(param);
			SetTimeUnderWater(stoi(param));
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
			success = true;
		}
		catch (const Exceptions& ex) {
			std::cout << ex.GetMessage() << endl;
		}
	} while (success == false);
}

void Submarine::RestoreObject(std::istringstream& ss)
{
	std::string element;
	getline(ss, element, ',');
	this->SetID(element);
	getline(ss, element, ',');
	this->SetLength(stod(element));
	getline(ss, element, ',');
	this->SetWidth(stod(element));
	getline(ss, element, ',');
	this->SetArmament(element);
	getline(ss, element, ',');
	ValidIntData(element);
	this->SetTimeUnderWater(stoi(element));
	getline(ss, element, ',');
	ValidData(element);
	this->SetSpeed(stod(element));
	getline(ss, element, ',');
	ValidIntData(element);
	this->SetAmountCrew(stoi(element));
}

void Submarine::PrintInfo() const
{
	std::cout << "\n-------- Submarine --------" << endl;
	std::cout << "ID: " << this->GetID() << endl;
	std::cout << "Length: " << this->GetLength() << endl;
	std::cout << "Width: " << this->GetWidth() << endl;
	std::cout << "Armament: " << this->GetArmament() << endl;
	std::cout << "Time under water: " << this->GetTimeUnderWater() << endl;
	std::cout << "Speed: " << this->GetSpeed() << endl;
	std::cout << "Amount of crew: " << this->GetAmountCrew() << endl;
}

void Submarine::EditInfo()
{
	string choice;
	string editParam;
	do {
		try {
		system("cls");
		cout << "--- Edit Menu ---" << endl;
		cout << "[1] Edit Length" << endl;
		cout << "[2] Edit Width" << endl;
		cout << "[3] Edit Armament" << endl;
		cout << "[4] Edit Time under water" << endl;
		cout << "[5] Edit Speed" << endl;
		cout << "[6] Edit Amount of crew" << endl;
		cout << "[7] Print current object" << endl;
		cout << "[0] Back" << endl;
		cout << "\nEnter your choice: ";
		getline(std::cin, choice);
		ValidIntData(choice);
		switch (stoi(choice)) {

		case 1:
			std::cout << "\nEnter new Length: ";
			getline(std::cin, editParam);
			ValidData(editParam);
			try {
				SetLength(stod(editParam));
				cout << "Parameter was successfully edited." << endl;
			}
			catch (const Exceptions& ex) {
				cout << ex.GetMessage() << endl;
			}
			break;
		case 2:
			std::cout << "\nEnter new Width: ";
			getline(std::cin, editParam);
			ValidData(editParam);
			try {
				SetWidth(stod(editParam));
				cout << "Parameter was successfully edited." << endl;
			}
			catch (const Exceptions& ex) {
				cout << ex.GetMessage() << endl;
			}
			break;
		case 3:
			cout << "\nEnter new Armament: ";
			getline(std::cin, armament);
			try {
				SetArmament(DeleteSpaces(armament));
				cout << "Parameter was successfully edited." << endl;
			}
			catch (const Exceptions& ex) {
				cout << ex.GetMessage() << endl;
			}
			break;
		case 4:
			cout << "\nEnter new Time under water: ";
			getline(std::cin, editParam);
			try {
				ValidIntData(editParam);
				SetTimeUnderWater(stoi(editParam));
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
		case 0: break;
		default:
			cout << "Invalid input! Please, enter 1/2/3/4/5/6/7 (0 - exit) number.";
			break;
		}
		std::cin.get();
		
		}
		catch (const Exceptions& ex) { cout << ex.GetMessage() << endl; }
		std::cin.ignore();
	} while (choice != "0");
}

std::ofstream& Submarine::Save(std::ofstream& out) const
{
	out << "Submarine" << "," << this->GetID() << "," << this->GetLength() << "," << this->GetWidth() << "," << this->GetArmament() << "," <<
		this->GetTimeUnderWater() << "," << this->GetSpeed() << "," << this->GetAmountCrew();
	return out;
}
