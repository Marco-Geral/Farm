#ifndef DRYSOIL_H
#define DRYSOIL_H
#include "Soil.h"
#include <string>

class DrySoil : public Soil {


public:
	DrySoil();
	void harvestCrops();
	void rain();
	std::string getName();
};

#endif
