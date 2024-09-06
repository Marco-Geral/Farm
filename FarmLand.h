#ifndef FARMLAND_H
#define FARMLAND_H
#include "FarmUnit.h"
#include "Iterator.h"
#include <vector>
#include <string>


class FarmLand : FarmUnit {

public:
	std::vector<FarmUnit*> units;

	Iterator* createIterator();
	double getTotalCapacity();
	std::string getCropType();
	void add(FarmUnit* unit);
	void remove(FarmUnit* unit);

};

#endif
