#include "FruitfulSoil.h"

FruitfulSoil::FruitfulSoil() {
	soilState =  "Fruitful";
}

void FruitfulSoil::harvestCrops(CropField* field) {
    // Higher crop yield (x3)
    double newAmount = field->getCurrentAmount() + field->getTotalCapacity() * 3;  // x3 yield
    field->setCurrentAmount(newAmount);
    std::cout << "Harvesting crops from Fruitful soil" << std::endl;
}

void FruitfulSoil::rain(CropField* field) {
    // Transition to FloodedSoil on rain
    field->setSoilState(new FloodedSoil());
    std::cout << "Excess rain has caused the Fruitful soil to become Flooded" << std::endl;
}

std::string FruitfulSoil::getName() {
	return this->soilState;
}
