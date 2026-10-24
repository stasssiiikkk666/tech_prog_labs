#include "Base.h"
#include "Exceptions.h"
#include <iostream>
#include <limits>
#include <sstream>
#include <exception>
#include <string>


Base::Base(){
	size++;
	this->speed = 0.0;
	this->amountCrew = 0;
	this->ID = size;
	std::cout << "\nBase class Default Constructor was called." << std::endl;
}

Base::Base(double speed, int amount)
{
	size++;
	SetSpeed(speed);
	SetAmountCrew(amount);
	SetID();
	std::cout << "Base class Constructor with parameters was called." << std::endl;
}

Base::~Base()
{
	std::cout << "Base class Virtual Destructor was called." << std::endl;
}

void Base::ValidData(const std::string& data) const
{
	double num;
	std::istringstream iss(data);
	if (!(iss >> num)) throw Exceptions{"Invalid input data type!"};
	iss >> std::ws; //пропуск пробелов ПОСЛЕ числа
	if (!iss.eof()) throw Exceptions{ "Invalid input data type!" };
}

void Base::ValidIntData(const std::string& data) const
{
	int num;
	std::istringstream iss(data);
	if (!(iss >> num)) throw Exceptions{ "Invalid input data type!" };
	iss >> std::ws; //пропуск пробелов ПОСЛЕ числа
	if (!iss.eof()) throw Exceptions{ "Invalid input data type!" };
}

std::string& Base::DeleteSpaces(std::string& data)
{
	if (data == "") throw Exceptions{ "Please, enter the data!" };
	size_t indexBegin = data.find_first_not_of(' ');
	size_t indexEnd = data.find_last_not_of(' ');
	data = data.substr(indexBegin, indexEnd-indexBegin+1);
	return data;
}

double Base::GetSpeed() const { return speed; }
int Base::GetAmountCrew() const { return amountCrew; }

void Base::SetSpeed(double speed) {
	if (speed < 0) throw Exceptions("Please, enter correct Speed (>=0)");
	this->speed = speed;
}

void Base::SetAmountCrew(int amountCrew) {
	if (amountCrew < 0) throw Exceptions("Please, enter correct Amount (>=0) of crew.");
	this->amountCrew = amountCrew;
}

void Base::SetID() {
	this->ID = size;
}

void Base::SetID(std::string& id)
{
	try {
		ValidIntData(id);
		this->ID = stoi(id);
	}
	catch (const Exceptions& ex) { std::cout << ex.GetMessage() << std::endl; }
}

void Base::SetSize(std::string size){
	ValidIntData(DeleteSpaces(size));
	this->size = stoi(size);
}

int Base::GetSize() { return size; }

unsigned int Base::GetID() const { return ID; }


