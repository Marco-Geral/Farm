#include "FarmLand.h"

FarmLand::FarmLand(const std::string& cropType, double capacity) {
    this->cropType = cropType;
    this->capacity = capacity;
    this->currentAmount = 0;
}

Iterator* FarmLand::createIterator(const std::string& type) {
    if (type == "BFS") {
        return new BreadthFirstIterator(this);
    } else if (type == "DFS") {
        return new DepthFirstIterator(this);
    }
    return nullptr;
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
