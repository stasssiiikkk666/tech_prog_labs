#include "Base.h"
#include "Exceptions.h"
#include <iostream>


Base::Base(){
	this->speed = 0.0;
	this->amountCrew = 0;
	std::cout << "\nBase class Default Constructor was called." << std::endl;
}

Base::Base(double speed, int amount)
{
	SetSpeed(speed);
	SetAmountCrew(amount);
	std::cout << "Base class Constructor with parameters was called." << std::endl;
}

Base::~Base()
{
	std::cout << "Base class Virtual Destructor was called." << std::endl;
}

void Base::ValidData(bool fail) const
{
	if (fail == true) throw Exceptions{ "Invalid input data type!" };
	
}

double Base::GetSpeed() const { return speed; }
int Base::GetAmountCrew() const { return amountCrew; }

void Base::SetSpeed(double speed) {
	if (speed < 0) throw Exceptions("Please, enter correct speed (>=0)");
	this->speed = speed;
}

void Base::SetAmountCrew(int amountCrew) {
	if (amountCrew < 0) throw Exceptions("Please, enter correct amount (>0) of crew.");
	this->amountCrew = amountCrew;
}

void Base::SetID(int id) {
	this->ID = id;
}

unsigned int Base::GetID() const { return ID; }
