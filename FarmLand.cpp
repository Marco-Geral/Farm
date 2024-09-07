#include "FarmLand.h"

Iterator* FarmLand::createIterator() {
	// TODO - implement FarmLand::createIterator
	throw "Not yet implemented";
}

double FarmLand::getTotalCapacity() {
	double sum = 0;
	for(int i = 0; i < units.size();i++){
		sum += units[i]->getTotalCapacity();
	}
	return sum;
}

std::string FarmLand::getCropType() {
    std::string crops;
    for(int i = 0; i < units.size(); i++) {
        crops += units[i]->getCropType();
        if (i < units.size() - 1) {
            crops += " | ";
        }
    }
    return crops;
}

void FarmLand::add(FarmUnit* unit) {
	units.push_back(unit);
}

void FarmLand::remove(FarmUnit* unit) {
	for(std::size_t i = 0; i < units.size(); i++) {
		if (units[i] == unit) {
			units.erase(units.begin() + i);
			break;
		}
	}
}
