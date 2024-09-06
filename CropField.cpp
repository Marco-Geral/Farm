#include "CropField.h"

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
