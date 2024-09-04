#ifndef SOIL_H
#define SOIL_H

class Soil {


public:
	virtual void harvestCrops() = 0;

	virtual void rain() = 0;

	virtual void getName() = 0;
};

#endif
