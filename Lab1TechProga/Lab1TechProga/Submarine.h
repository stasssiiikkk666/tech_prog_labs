#pragma once
#include <iostream>
#include <string>
#include "Base.h"

class Submarine : public Base {
private:
	double length;
	double width;
	int timeUnderWater;
	std::string armament; //Торпедное — Torpedoes, Ракетное — Missiles, Смешанное — Mixed, Минное — Mines, None - никакого
public: 
	Submarine(double length, double width, int timeUnderWater, std::string armament, double speed, int amount) :
		Base(speed, amount) {
		SetLength(length);
		SetWidth(width);
		SetTimeUnderWater(timeUnderWater);
		SetArmament(armament);
		std::cout << "Submarine class Constructor with parameters was called." << std::endl;
	};
	Submarine();
	~Submarine();
	void SetLength(double length);
	void SetWidth(double width);
	void SetTimeUnderWater(int timeUnderWater);
	void SetArmament(std::string armament);
	
	double GetLength() const;
	double GetWidth() const;
	int GetTimeUnderWater() const;
	std::string GetArmament() const;

	void CreateObject() override;
	void PrintInfo() const override;
	void EditInfo() override;
};