#include "CropField.h"

CropField::CropField(const std::string& cropType, double capacity, Soil* soilState)
    : soilState(soilState)  // Initialize soilState
{
    this->cropType = cropType;
    this->capacity = capacity;
	this->currentAmount = 0;
}

std::string CropField::getSoilStateName() {
        return soilState->getName();
}

double CropField::getTotalCapacity() {
    return capacity;
}

std::string CropField::getCropType() {
    return cropType;
}

void CropField::setSoilState(Soil* newSoilState) {
    soilState = newSoilState;  // Set new soil state
}

void CropField::harvestCrops(CropField* field) {
    soilState->harvestCrops(this);  // Delegate to current soil state
}

void CropField::rain(CropField* field) {
    soilState->rain(this);  // Delegate to current soil state
}

bool CropField::needsFertilization() {
    return dynamic_cast<DrySoil*>(soilState) != nullptr;
}
