#pragma once
#include <iostream>
#include <string>
#include "Base.h"
using namespace std;

class Keeper {
private:
	Base** massive;
	int size;
public:
	Base* SearchObject(int index);
	void PrintAll() const;
	bool DeleteObject(unsigned int id);
	void AddObject(Base* obj);
	void Save() const;
	void Restoring() const;
	Keeper();
	~Keeper();

	void SetMassive() { this->massive = nullptr; }
	Base** GetMassive() const { return massive; }

	void SetSize(int size) { this->size = size; }
	int GetSize() { return size; }
};