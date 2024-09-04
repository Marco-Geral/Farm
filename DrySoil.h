#ifndef DRYSOIL_H
#define DRYSOIL_H
#include "Soil.h"

class DrySoil : Soil {


public:
	void harvestCrops();

	void rain();

	void getName();
};

#endif
