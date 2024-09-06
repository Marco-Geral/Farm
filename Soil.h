#ifndef SOIL_H
#define SOIL_H
#include <string>

class Soil {

protected:
	std::string soilState;

public:
	virtual void harvestCrops() = 0;
	virtual void rain() = 0;
	virtual std::string getName() = 0;
};

#endif
