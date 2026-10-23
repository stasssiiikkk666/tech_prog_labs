#include "Speedboat.h"
#include "Exceptions.h"
#include <string>
#include <iostream>
using namespace std;

Speedboat::Speedboat()
{
	this->purpose = '-';
	this->material = '-';
	this->charachteristics = '-';
	std::cout << "Speedboat Default Constructor was called." << std::endl;
}

Speedboat::~Speedboat() { std::cout << "Speedboat class Destructor was called." << std::endl; }

void Speedboat::SetPurpose(std::string purpose) {
	if (purpose == "") throw Exceptions{ "Please, enter type of the armament Sailboat." };
	if (purpose != "Recreational" && purpose != "Fishing" && purpose != "Rescue" && purpose != "Patrol") 
		throw Exceptions{ "The Speedboat's Purpose must be one of Recreational/Fishing/Rescue/Patrol." };
	this->purpose = purpose;
}

void Speedboat::SetMaterial(std::string material) {
	if (material == "") throw Exceptions{ "Please, enter type of the armament Sailboat." };
	if (material != "Fiberglass" && material != "Aluminum" && material != "Steel" && material != "Wood")
		throw Exceptions{ "The Speedboat's Material must be one of Fiberglass/Aluminum/Steel/Wood." };
	this->material = material;
}

void Speedboat::SetCharachteristics(std::string charachteristics)
{
	if (charachteristics == "") throw Exceptions{ "Please, enter type of the armament Sailboat." };
	if (charachteristics != "High-speed" && charachteristics != "Stable" && charachteristics != "Maneuverable")
		throw Exceptions{ "The Speedboat's Charachteristics must be one of High-speed/Stable/Maneuverable." };
	this->charachteristics = charachteristics;
}

std::string Speedboat::GetPurpose() const { return this->purpose; }
std::string Speedboat::GetMaterial() const { return this->material; }
std::string Speedboat::GetCharachteristics() const { return this->charachteristics; }

void Speedboat::CreateObject()
{
	std::string param;
	bool success = false;
	do {
		std::cout << "\nEnter new Purpose: ";
		getline(std::cin, purpose);
		try {
			SetPurpose(DeleteSpaces(purpose));
			success = true;
		}
		catch (const Exceptions& ex) {
			std::cout << ex.GetMessage() << std::endl;
		}
	} while (success == false);

	do {
		success = false;
		std::cout << "\nEnter new Material: ";
		getline(std::cin, material);
		try {
			SetMaterial(DeleteSpaces(material));
			success = true;
		}
		catch (const Exceptions& ex) {
			std::cout << ex.GetMessage() << std::endl;
		}
	} while (success == false);

	do {
		success = false;
		cout << "\nEnter new Charachteristics: ";
		getline(cin, charachteristics);
		try {
			SetCharachteristics(DeleteSpaces(charachteristics));
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

void Speedboat::PrintInfo() const{
	std::cout << "\n-------- Speedboat --------" << endl;
	std::cout << "ID: " << this->GetID() << endl;
	std::cout << "Purpose:" << this->GetPurpose() << endl;
	std::cout << "Material: " << this->GetMaterial() << endl;
	std::cout << "Charachteristics: " << this->GetCharachteristics() << endl;
	std::cout << "Speed: " << this->GetSpeed() << endl;
	std::cout << "Amount of crew: " << this->GetAmountCrew() << endl;
}

void Speedboat::EditInfo()
{
	string choice;
	string editParam;
	do {
		try {
			system("cls");
			cout << "--- Edit Menu ---" << endl;
			cout << "[1] Edit Purpose" << endl;
			cout << "[2] Edit Material" << endl;
			cout << "[3] Edit Charachteristics" << endl;
			cout << "[4] Edit Speed" << endl;
			cout << "[5] Edit Amount of crew" << endl;
			cout << "[6] Print current object" << endl;
			cout << "[0] Back" << endl;
			cout << "\nEnter your choice: ";
			getline(std::cin, choice);
			ValidIntData(choice);
			switch (stoi(choice)) {

			case 1:
				std::cout << "\nEnter new Purpose: ";
				getline(std::cin, editParam);
				try {
					SetPurpose(DeleteSpaces(editParam));
					cout << "Parameter was successfully edited." << endl;
				}
				catch (const Exceptions& ex) {
					cout << ex.GetMessage() << endl;
				}
				break;
			case 2:
				std::cout << "\nEnter new Material: ";
				getline(std::cin, editParam);
				try {
					SetMaterial(DeleteSpaces(editParam));
					cout << "Parameter was successfully edited." << endl;
				}
				catch (const Exceptions& ex) {
					cout << ex.GetMessage() << endl;
				}
				break;
			case 3:
				cout << "\nEnter new Charachteristics: ";
				getline(std::cin, editParam);
				try {
					SetCharachteristics(DeleteSpaces(editParam));
					cout << "Parameter was successfully edited." << endl;
				}
				catch (const Exceptions& ex) {
					cout << ex.GetMessage() << endl;
				}
				break;
			case 4:
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
			case 5:
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
			case 6:
				this->PrintInfo();
				break;
			default:
				cout << "Invalid input! Please, enter 1/2/3/4/5/6 (0 - exit) number.";
				break;
			}
			std::cin.get();
		}
		catch (const Exceptions& ex) { cout << ex.GetMessage() << endl; }
		std::cin.ignore();
	} while (choice != "0");
}


