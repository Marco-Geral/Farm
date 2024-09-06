#ifndef FRUITFULSOIL_H
#define FRUITFULSOIL_H
#include "Soil.h"
#include <string>

class FruitfulSoil : public Soil {


public:
	FruitfulSoil();
	void harvestCrops();
	void rain();
	std::string getName();
};

#endif
