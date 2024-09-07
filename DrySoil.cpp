#include "DrySoil.h"

DrySoil::DrySoil() {
	soilState = "Dry";
}
void DrySoil::harvestCrops(CropField* field) {
    // Minimal crop yield (x1)
    double newAmount = field->getCurrentAmount() + field->getTotalCapacity() * 1;  // x1 yield
    field->setCurrentAmount(newAmount);
}

void DrySoil::rain(CropField* field) {
    // Transition to FruitfulSoil on rain
    field->setSoilState(new FruitfulSoil());
}

std::string DrySoil::getName() {
	return this->soilState;
}
