#ifndef DRYSOIL_H
#define DRYSOIL_H
#include "Soil.h"
#include "CropField.h"
#include "FruitfulSoil.h"
#include <string>
#include <iostream>

class DrySoil : public Soil {


public:
	DrySoil();
	void harvestCrops(CropField* field);
	void rain(CropField* field);
	std::string getName();
};

#endif
