#pragma once
#include <iostream>
#include <string>

class Base {
private:
	double speed;
	int amountCrew;
	unsigned int ID;
	static inline int size{};
public: 
	Base();
	Base(double speed, int amount);
	virtual ~Base();
	virtual void CreateObject() = 0;
	virtual void PrintInfo() const = 0;
	virtual void EditInfo() = 0;
	//virtual void DeleteObject() = 0;
	void ValidData(const std::string& data) const;
	void ValidIntData(const std::string& data) const;

	double GetSpeed() const;
	int GetAmountCrew() const;

	void SetSpeed(double speed);
	void SetAmountCrew(int amountCrew);

	void SetID();
	unsigned int GetID() const;
};

