#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Base.h"

class Speedboat : public Base {
private:
	std::string purpose; //назначение Recreational (прогулочный) , Fishing, Rescue, Patrol
	std::string material; //Fiberglass-стеклопластик, Aluminum, Steel, Wood 
	std::string charachteristics; //ходовые качества: High-speed, Stable, Maneuverable — скоростной, устойчивый, манёвренный
public:
	Speedboat(std::string purpose, std::string material, std::string charachteristics, double speed, int amount) :
		Base(speed, amount) {
		SetPurpose(purpose);
		SetMaterial(material);
		SetCharachteristics(charachteristics);
		std::cout << "Speedboat class Constructor with parameters was called." << std::endl;
	};
	Speedboat();
	~Speedboat();
	void SetPurpose(std::string purpose);
	void SetMaterial(std::string material);
	void SetCharachteristics(std::string charachteristics);
	
	std::string GetPurpose() const;
	std::string GetMaterial() const;
	std::string GetCharachteristics() const;

	void CreateObject() override;
	void RestoreObject(std::istringstream& ss) override;
	void PrintInfo() const override;
	void EditInfo() override;

	std::ofstream& Save(std::ofstream& out) const override;
};