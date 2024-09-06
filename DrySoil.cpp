#include "DrySoil.h"

DrySoil::DrySoil() {
	soilState = "Dry";
}
void DrySoil::harvestCrops() {
	// TODO - implement DrySoil::harvestCrops
	throw "Not yet implemented";
}

void DrySoil::rain() {
	// TODO - implement DrySoil::rain
	throw "Not yet implemented";
}

std::string DrySoil::getName() {
	return this->soilState;
}
