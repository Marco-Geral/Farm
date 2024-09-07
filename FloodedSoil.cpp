#include "FloodedSoil.h"

FloodedSoil::FloodedSoil() {
	soilState = "Flooded";
}

void FloodedSoil::harvestCrops(CropField* field) {
    // No crop yield
    // Do nothing, no crops can be harvested
}

void FloodedSoil::rain(CropField* field) {
    // No state change on rain when flooded
    // Do nothing, already flooded
}

std::string FloodedSoil::getName() {
	return this->soilState;
}
