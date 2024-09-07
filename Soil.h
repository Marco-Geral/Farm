#ifndef SOIL_H
#define SOIL_H
#include <string>
#include "CropField.h"

class CropField;

class Soil {

protected:
	std::string soilState;

public:
	virtual void harvestCrops(CropField* field) = 0;
	virtual void rain(CropField* field) = 0;
	virtual std::string getName() = 0;
};

#endif
