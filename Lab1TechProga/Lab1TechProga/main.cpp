#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include "Sailboat.h"
#include "Speedboat.h"
#include "Submarine.h"
#include "Keeper.h"
#include "Exceptions.h"
#include "Base.h"
using namespace std;

void ClearScreen();
void AddShip(int choice);
void ValidData(const string& param);
void ValidData();
Keeper keeper;

int main() {
	string choice;
	string id;
	std::ofstream out("lab1.txt", ios::app);

	do {
		try {
			ClearScreen();
			cout << "--- MAIN MENU ---\n";
			cout << "[1] Add" << endl;
			cout << "[2] Delete" << endl;
			cout << "[3] Print all" << endl;
			cout << "[4] Search" << endl;
			cout << "[5] Edit Ship" << endl;
			cout << "[6] Save all" << endl;
			cout << "[7] Save object" << endl;
			cout << "[8] Restore from file" << endl;
			cout << "[0] Exit" << endl;
			cout << "Enter your choice: ";
			getline(std::cin, choice);
			//cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

			ValidData(choice);
			switch (stoi(choice)) {
			case 1: {
				string choice;
				ClearScreen();
				cout << "--- Choose what kind of ship you want to ADD ---\n";
				cout << "[1] Sailboat" << endl;
				cout << "[2] Speedboat" << endl;
				cout << "[3] Submarine" << endl;
				cout << "[0] Back" << endl;
				cout << "Enter your choice: ";
				getline(cin, choice);
				try {
					ValidData(choice);
					AddShip(stoi(choice));
				}
				catch (const Exceptions& ex) { cout << ex.GetMessage() << endl; }
				break;
			}
			case 2:
				try {
					ValidData();
					cout << "Enter ID of the ship: ";
					getline(cin, id);
					ValidData(id);
					keeper.DeleteObject(stoi(id));
				}
				catch (const Exceptions& ex) {
					cout << ex.GetMessage() << endl;
				}
				break;
			case 3:
				try {
					ValidData();
					keeper.PrintAll();
				}
				catch (const Exceptions& ex) {
					cout << ex.GetMessage() << endl;
				}
				break;
			case 4:
				try {
					ValidData();
					cout << "Enter ID of the ship: ";
					getline(cin, id);
					ValidData(id);
					Base* obj = keeper.SearchObject(stoi(id));
					obj->PrintInfo();
				}
				catch (const Exceptions& ex) {
					cout << ex.GetMessage() << endl;
				}
				break;
			case 5:
				try {
					ValidData();
					cout << "Enter ID of the ship: ";
					getline(cin, id);
					ValidData(id);
					Base* obj = keeper.SearchObject(stoi(id));
					ClearScreen();
					obj->EditInfo();
				}
				catch (const Exceptions& ex) {
					cout << ex.GetMessage() << endl;
				}
				break;
			case 6:
				try {
					ValidData();
					keeper.Save();
				}
				catch (const Exceptions& ex) {
					cout << ex.GetMessage() << endl;
				}
				break;
			case 7:
				try {
					ValidData();
					cout << "Enter ID of the ship: ";
					getline(cin, id);
					ValidData(id);
					keeper.SaveObject(stoi(id));
				}
				catch (const Exceptions& ex) {
					cout << ex.GetMessage() << endl;
				}
				break;
			case 8:
				try {
					keeper.Restoring();
				}
				catch (const Exceptions& ex) {
					cout << ex.GetMessage() << endl;
					//keeper.~Keeper();
				}
				break;
			case 0:
				break;
			default:
				cout << "Invalid input! Please, enter 1/2/3/4/5/6/7/8 (0 - exit) number.";
				break;
			}
			cin.ignore();
		}
		catch (const Exceptions& ex) {
			cout << ex.GetMessage() << std::endl; cin.get();
		}
	} while (choice != "0");
}

void ClearScreen() { system("cls"); }

void AddShip(int choice)
{
	Base* obj = nullptr;
	switch (choice) {
	case 1:
		obj = new Sailboat();
		obj->CreateObject();
		keeper.AddObject(obj);
		cout << "New Sailboat succesfully was created!";
		break;
	case 2:
		obj = new Speedboat();
		obj->CreateObject();
		keeper.AddObject(obj);
		cout << "New Speedboat succesfully was created!";
		break; 
	case 3:
		obj = new Submarine();
		obj->CreateObject();
		keeper.AddObject(obj);
		cout << "New Sailboat succesfully was created!";
		break;
	case 0: break;
	default:
		cout << "Invalid input! Please, enter 1/2/3 number.";
	}
}


void ValidData(const std::string& param)
{
	int idInt;
	std::istringstream iss(param);
	if (!(iss >> idInt)) throw Exceptions{ "Invalid input data type!" };
	iss >> std::ws; //пропуск пробелов ПОСЛЕ числа
	if (!iss.eof()) throw Exceptions{ "Invalid input data type!" };
}

void ValidData()
{
	if (keeper.GetSize() == 0) throw Exceptions{ "Before delete/edit/print/search/save add Ship or restore" };
}
