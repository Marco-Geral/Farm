#ifndef SOIL_H
#define SOIL_H
#include <string>
#include "CropField.h"

class CropField;

class Soil {

protected:
	std::string soilState;

public:
	virtual ~Soil() {}
	virtual void harvestCrops(CropField* field) = 0;
	virtual void rain(CropField* field) = 0;
	virtual std::string getName() = 0;

	virtual bool isDrySoil() const { return false; }
};

#endif
