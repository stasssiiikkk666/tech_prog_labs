#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Base.h"
using namespace std;

class Keeper {
private:
	Base** massive;
	int size;
public:
	Base* SearchObject(unsigned int id);
	void PrintAll() const;
	bool DeleteObject(unsigned int id);
	void AddObject(Base* obj);
	void Save() const;
	void SaveObject(unsigned int id);
	void Restoring();
	bool IsUnique(unsigned int id);
	Keeper();
	~Keeper();

	void SetMassive() { this->massive = nullptr; }
	Base** GetMassive() const { return massive; }

	void SetSize(int size) { this->size = size; }
	int GetSize()  const  { return size; }
};