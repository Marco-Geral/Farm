#ifndef CROPFIELD_H
#define CROPFIELD_H
#include "FarmUnit.h"
#include "Soil.h"
#include <string>

class CropField : FarmUnit {

public:
	Soil* soilState;
	//std::string cropType;

	std::string getSoilStateName();
	double getTotalCapacity();
	std::string getCropType();
};

#endif
