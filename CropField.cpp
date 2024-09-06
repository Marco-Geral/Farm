#include "CropField.h"

std::string CropField::getSoilStateName() {
    if (soilState != nullptr) {
        return soilState->getName();
    } else {
        return "No soil state available";
    }
}


double CropField::getTotalCapacity() {
	return this->FarmUnit::getTotalCapacity();
}

std::string CropField::getCropType() {
	return this->FarmUnit::getCropType();
}