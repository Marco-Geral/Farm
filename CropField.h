#ifndef CROPFIELD_H
#define CROPFIELD_H
#include "FarmUnit.h"
#include "Soil.h"
#include <string>

class CropField : public FarmUnit {
	
public:
	Soil* soilState;
	CropField(const std::string& cropType, double capacity, Soil* soilState);
	std::string getSoilStateName();
	double getTotalCapacity();
	std::string getCropType();

    void setSoilState(Soil* newSoilState);  // To transition between soil states
    void harvestCrops(CropField* field);  // Delegate to soilState
    void rain(CropField* field);  // Delegate to soilState
};

#endif
