#ifndef FLOODEDSOIL_H
#define FLOODEDSOIL_H
#include "Soil.h"
// #include "CropField.h"
#include <string>
#include <iostream>

class CropField;

class FloodedSoil : public Soil {

public:
	FloodedSoil();
	void harvestCrops(CropField* field);
	void rain(CropField* field);
	std::string getName();
};

#endif
