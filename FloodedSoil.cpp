#include "FloodedSoil.h"

FloodedSoil::FloodedSoil() {
	soilState = "Flooded";
}

void FloodedSoil::harvestCrops() {
	// TODO - implement FloodedSoil::harvestCrops
	throw "Not yet implemented";
}

void FloodedSoil::rain() {
	// TODO - implement FloodedSoil::rain
	throw "Not yet implemented";
}

std::string FloodedSoil::getName() {
	return this->soilState;
}
