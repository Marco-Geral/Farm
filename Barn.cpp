#include "Barn.h"

Barn::Barn(const std::string& cropType, double capacity) {
    this->cropType = cropType;
    this->capacity = capacity;
    this->currentAmount = 0;
}

std::string Barn::getCropType() {
	return cropType;
}

double Barn::getTotalCapacity() {
	return capacity;
}
