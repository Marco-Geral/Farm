#ifndef CROPFIELD_H
#define CROPFIELD_H
#include "FarmUnit.h"
#include "Soil.h"
#include <string>

class CropField : public FarmUnit {
	
private:
	Soil* soilState;
public:
	CropField(const std::string& cropType, double capacity, Soil* soilState);
	std::string getSoilStateName();
	double getTotalCapacity();
	std::string getCropType();
};

#endif
