#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

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
	virtual void RestoreObject(std::istringstream& ss) = 0;
	virtual void PrintInfo() const = 0;
	virtual void EditInfo() = 0;
	void ValidData(const std::string& data) const;
	void ValidIntData(const std::string& data) const;
	double GetSpeed() const;
	int GetAmountCrew() const;

	void SetSpeed(double speed);
	void SetAmountCrew(int amountCrew);

	void SetID();
	void SetID(std::string& id);

	void SetSize(std::string size);
	static int GetSize();
	unsigned int GetID() const;

	std::string& DeleteSpaces(std::string& data);
	virtual std::ofstream& Save(std::ofstream& out) const = 0;
	//virtual std::ifstream& Restore(std::ifstream& in) const = 0;
};

