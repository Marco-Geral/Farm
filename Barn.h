#ifndef BARN_H
#define BARN_H
#include "FarmUnit.h"
#include <string>

class Barn : FarmUnit {

private:
	std::string cropType;
	double capacity;

public:
	std::string getCropType();

	double getTotalCapacity();
};

#endif
