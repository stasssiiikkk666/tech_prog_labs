#include "Keeper.h"
#include "Exceptions.h"
#include <iostream>



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
	//cout << "New object was created sucessfully.";
}

Keeper::Keeper()
{
	SetSize(0);
	SetMassive();
	cout << "Keeper Default Constructor was called." << endl;
}

Keeper::~Keeper()
{
	for (int i = 0; i < GetSize(); i++) {
		delete massive[i];
		massive[i] = nullptr;
	}
	delete[] massive;
	this->massive = nullptr;
	cout << "Keeper Destructor was called." << endl;
}

Base* Keeper::SearchObject(int id)
{
	for (int i = 0; i < GetSize(); i++) {
		if (massive[i]->GetID() == id) {
			return massive[i];
		}
	}
	throw Exceptions{ "Objects with ID " + to_string(id) + " haven't found." };
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
