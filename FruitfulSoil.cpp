#include "FruitfulSoil.h"

FruitfulSoil::FruitfulSoil() {
	soilState =  "Fruitful";
}

void FruitfulSoil::harvestCrops() {
	// TODO - implement FruitfulSoil::harvestCrops
	throw "Not yet implemented";
}

void FruitfulSoil::rain() {
	// TODO - implement FruitfulSoil::rain
	throw "Not yet implemented";
}

std::string FruitfulSoil::getName() {
	return this->soilState;
}
