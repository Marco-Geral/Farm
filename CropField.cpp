#include "CropField.h"

CropField::CropField(const std::string& cropType, double capacity, Soil* soilState)
    : soilState(soilState)  // Initialize soilState
{
    this->cropType = cropType;
    this->capacity = capacity;
	this->currentAmount = 0;
}

std::string CropField::getSoilStateName() {
    if (soilState != nullptr) {
        return soilState->getName();
    } else {
        return "No soil state available";
    }
}

double CropField::getTotalCapacity() {
    return capacity;
}

std::string CropField::getCropType() {
    return cropType;
}
