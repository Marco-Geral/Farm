#include "FloodedSoil.h"

FloodedSoil::FloodedSoil() {
	soilState = "Flooded";
}

void FloodedSoil::harvestCrops(CropField* field) {
    std::cout << "Harvest was unsuccessful beacuse soil is Flooded" << std::endl;
}

void FloodedSoil::rain(CropField* field) {
    std::cout << "Rain continues and soil remains Flooded..." << std::endl;
}

std::string FloodedSoil::getName() {
	return this->soilState;
}
