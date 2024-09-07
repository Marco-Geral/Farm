#ifndef FRUITFULSOIL_H
#define FRUITFULSOIL_H
#include "Soil.h"
#include "CropField.h"
#include "FloodedSoil.h"
#include <string>
#include <iostream>

class FruitfulSoil : public Soil {


public:
	FruitfulSoil();
	void harvestCrops(CropField* field);
	void rain(CropField* field);
	std::string getName();
};

#endif
