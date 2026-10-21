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

double Base::GetSpeed() const { return speed; }
int Base::GetAmountCrew() const { return amountCrew; }

void Base::SetSpeed(double speed) {
	if (speed < 0) throw Exceptions("Please, enter correct speed (>=0)");
	this->speed = speed;
}

void Base::SetAmountCrew(int amountCrew) {
	if (amountCrew < 0) throw Exceptions("Please, enter correct amount (>=0) of crew.");
	this->amountCrew = amountCrew;
}

void Base::SetID() {
	this->ID = size;
}

unsigned int Base::GetID() const { return ID; }
