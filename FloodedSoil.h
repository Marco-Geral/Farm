#ifndef FLOODEDSOIL_H
#define FLOODEDSOIL_H
#include "Soil.h"
#include <string>

class FloodedSoil : public Soil {


public:
	FloodedSoil();
	void harvestCrops();
	void rain();
	std::string getName();
};

#endif
