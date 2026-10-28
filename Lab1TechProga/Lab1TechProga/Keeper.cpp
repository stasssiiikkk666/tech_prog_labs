#include "Sailboat.h"
#include "Speedboat.h"
#include "Submarine.h"
#include "Keeper.h"
#include "Exceptions.h"
#include "Base.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void Keeper::AddObject(Base* obj)
{
	if (size == 0) {
		massive = new Base*[size + 1];
	}
	else {
		Base** massiveCopy = new Base* [size + 1];
		for (int i = 0; i < size; i++) {
			massiveCopy[i] = massive[i];
		}
		delete[] massive;
		massive = massiveCopy;
	}
	
	massive[size] = obj;
	size++;
	SetSize(size);
}

void Keeper::Save() const{
	std::ofstream out;
	out.open("lab1.txt");
	if (out.is_open()) {
		for (int i = 0; i < GetSize(); i++) {
			massive[i]->Save(out) << endl;
		}
	}
	out << "Last ID:" << Base::GetSize() << endl;
	if (!out.is_open()) throw Exceptions{ "The file lab1.txt could not be opened." };
	out.close();
	cout << "Objects have been saved successfully." << endl;
}

void Keeper::SaveObject(unsigned int id)
{
	bool alreadyAdd = IsUnique(id);
	Base* obj = SearchObject(id);
	std::ofstream out;
	
	out.open("lab1.txt", ios::in); 
	if (!out.is_open()) throw Exceptions{ "The file lab1.txt could not be opened." };
	if (out.is_open() && alreadyAdd == false) {
		std::ofstream outTmp("lab1tmp.txt", ios::trunc);
		std::ifstream inTmp("lab1.txt");
		
		if (!outTmp.is_open() || !inTmp.is_open()) 
			throw Exceptions{ "The file lab1.txt could not be opened." };
		string line;
		if (outTmp.is_open() && inTmp.is_open()) { //запись во временный файл
			while (getline(inTmp, line)) {
				if (line.find(',') == line.npos) { continue; }
				outTmp << line << endl;
			}
			obj->Save(outTmp) << endl;
		}
		out.close();
		outTmp.close();
		inTmp.close();
		out.open("lab1.txt", ios::trunc);
		std::ifstream in("lab1tmp.txt");
		if (in.is_open() && out.is_open()) {
			while (getline(in, line)) {
				out << line << endl;
			}
		}
		out << "Last ID:" << Base::GetSize() << endl;
		out.close();
		in.close();
		cout << "Object has been saved successfully." << endl;
	}
	else {
		cout << "Object is being already exist." << endl;
	}
}

void Keeper::Restoring()
{
	std::ifstream in("lab1.txt");
	std::string line, element;
	Base* obj = nullptr;
	bool fail = false;
	if (in.is_open()) {
		if (GetSize() != 0) {
			Keeper::~Keeper();
		}
		while (getline(in, line)) {
			std::istringstream ss(line);
			while (getline(ss, element, ',')) {
				if (element == "Sailboat") {
					try {
						obj = new Sailboat();
						obj->RestoreObject(ss);
						AddObject(obj);
					}
					catch (const Exceptions& ex) {
						cout << ex.GetMessage() << endl;
						delete obj;
						fail = true;
						break;
					}
				}
				
				else if (element == "Speedboat") {
					try {
						obj = new Speedboat();
						obj->RestoreObject(ss);
						AddObject(obj);
					}
					catch (const Exceptions& ex) {
						cout << ex.GetMessage() << endl;
						delete obj;
						fail = true;
						break;
					}
				}
				else if (element == "Submarine") {
					try {
						obj = new Submarine();
						obj->RestoreObject(ss);
						AddObject(obj);
					}
					catch (const Exceptions& ex) {
						cout << ex.GetMessage() << endl;
						delete obj;
						fail = true;
						break;
					}
				}
				else if (element.substr(0,7) == "Last ID") {
					size_t posBegin = element.find(':') + 1;
					size_t posEnd = element.find('\n') + 1;
					obj->SetSize(element.substr(posBegin, element.length() - posBegin));
				}
			}
			if (fail == true) { 
				Keeper::~Keeper();
				break; 
			}
		}
	}
	if (!in.is_open()) throw Exceptions{ "The file lab1.txt could not be opened." };

	in.close();
}

bool Keeper::IsUnique(unsigned int id)
{
	bool alreadyAdd = false;
	std::ifstream in("lab1.txt");
	string line, idStr;
	while (getline(in, line)) {
		if (line.find(',') == line.npos) {continue; }
		size_t posBegin = line.find_first_of(',') + 1; //начало айди
		size_t posEnd = line.find(',', posBegin);
		idStr = line.substr(posBegin, posEnd - posBegin);
		if (id == stoi(idStr)) {
			alreadyAdd = true;
			in.close();
			return alreadyAdd;
		}
	}
	if (!in.is_open()) throw Exceptions{ "The file lab1.txt could not be opened." };
	in.close();
	return alreadyAdd;
}

Keeper::Keeper()
{
	SetSize(0);
	SetMassive();
	cout << "Keeper Default Constructor was called." << endl;
}

Keeper::Keeper(const Keeper& massive)
{
	int size = massive.GetSize();
	this->massive = new Base* [size];
	for (int i = 0; i < size; i++) {
		this->massive[i] = massive.massive[i]->CopyObject();
	}
}

Keeper::~Keeper()
{
	if (GetSize() > 0) {
		for (int i = 0; i < GetSize(); i++) {
			delete massive[i];
			massive[i] = nullptr;
		}
		delete[] massive;
		this->massive = nullptr;
		size = 0;
		cout << "Keeper Destructor was called." << endl;
	}
}

Base* Keeper::SearchObject(unsigned int id)
{
	for (int i = 0; i < GetSize(); i++) {
		if (massive[i]->GetID() == id) {
			return massive[i];
		}
	}
	throw Exceptions{ "Object with ID " + to_string(id) + " haven't found." };
}

void Keeper::PrintAll() const
{
	if (size == 0) throw Exceptions{ "Before print add objects!" };
	
	for (int i = 0; i < size; i++) {
		massive[i]->PrintInfo(); //должно быть исклбчение когда массив пустой
		cout << endl;
	}

}

bool Keeper::DeleteObject(unsigned int id)
{
	bool flag = false;
	for (int i = 0; i < GetSize(); i++) {
		if (massive[i]->GetID() == id) {
			delete massive[i];
			massive[i] = nullptr;
			for (int j = i; j < GetSize() - 1; j++) {
				massive[j] = massive[j + 1];
			}
			massive[GetSize() - 1] = nullptr;
			SetSize(size - 1);
			return true;
			break;
		}
	}
	if (flag == false) throw Exceptions{ "Objects with ID " + to_string(id) + " haven't found." };
}
