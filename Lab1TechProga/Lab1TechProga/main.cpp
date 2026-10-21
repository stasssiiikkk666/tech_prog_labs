#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include "Sailboat.h"
#include "Speedboat.h"
#include "Submarine.h"
#include "Keeper.h"
#include "Exceptions.h"
using namespace std;

void ClearScreen();
void AddShip(int choice);
void ValidData(const string& id);
void ValidData();
Keeper keeper;
//unsigned int ID = 0;

int main() {
	setlocale(LC_ALL, "RU");
	int choice = 0;
	//int id = 0;
	string id;

	do {
		ClearScreen();
		cout << "--- MAIN MENU ---\n";
		cout << "[1] Add" << endl;
		cout << "[2] Delete" << endl;
		cout << "[3] Print all" << endl;
		cout << "[4] Search" << endl;
		cout << "[5] Edit Ship" << endl;
		cout << "Enter your choice: ";
		std::cin >> choice;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		switch (choice) {
		case 1:
			ClearScreen();
			int choice;
			cout << "--- Choose what kind of ship you want to ADD ---\n";
			cout << "[1] Sailboat" << endl;
			cout << "[2] Speedboat" << endl;
			cout << "[3] Submarine" << endl;
			cout << "[0] Back" << endl;
			cout << "Enter your choice: ";
			cin >> choice;
			AddShip(choice);
			break;
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
				cin >> id;
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
				cin >> id;
				ValidData(id);
				Base* obj = keeper.SearchObject(stoi(id));
				ClearScreen();
				obj->EditInfo();
			}
			catch (const Exceptions& ex) {
				cout << ex.GetMessage() << endl;
			}
			break;
		
		case 0: return 0;
		default:
			cout << "Invalid input! Please, enter 1/2/3/4/5 (0 - exit) number.";
			break;
		}
		cin.ignore();
		cin.get();
	} while (choice != 0);
}

void ClearScreen() { system("cls"); }

void AddShip(int choice)
{
	Base* obj = nullptr;
	switch (choice) {
	case 1:
		obj = new Sailboat();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		obj->CreateObject();
		keeper.AddObject(obj);
		cout << "New Sailboat succesfully was created!";
		break;
	case 2:
		break;
		//Speedboat speedboat1;
	case 3:
		break;
		//Submarine submarine1;
	default:
		cout << "Invalid input! Please, enter 1/2/3 number.";
	}

}


void ValidData(const std::string& id)
{
	int idInt;
	std::istringstream iss(id);
	if (!(iss >> idInt)) throw Exceptions{ "Invalid input data type!" };
	iss >> std::ws; //пропуск пробелов ПОСЛЕ числа
	if (!iss.eof()) throw Exceptions{ "Invalid input data type!" };
}

void ValidData()
{
	if (keeper.GetSize() == 0) throw Exceptions{ "Before delete/edit/print/search add Ship" };
}

