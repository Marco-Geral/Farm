#ifndef FARMLAND_H
#define FARMLAND_H
#include "FarmUnit.h"
#include "Iterator.h"
#include <vector>


class FarmLand : FarmUnit {

public:
	std::vector<FarmUnit*> Units;

	Iterator* createIterator();
	double getTotalCapacity();
	std::string getCropType();
};

#endif
