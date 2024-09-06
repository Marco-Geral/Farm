#ifndef CROPFIELD_H
#define CROPFIELD_H
#include "FarmUnit.h"
#include "Soil.h"

class CropField : FarmUnit {

public:
	Soil* soilState;
	//std::string cropType;

	Soil* getSoilStateName();
	double getTotalCapacity();
	std::string getCropType();
};

#endif
