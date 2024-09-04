#ifndef FLOODEDSOIL_H
#define FLOODEDSOIL_H
#include "Soil.h"

class FloodedSoil : Soil {


public:
	void harvestCrops();

	void rain();

	void getName();
};

#endif
