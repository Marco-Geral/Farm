#ifndef FARMLAND_H
#define FARMLAND_H
#include "FarmUnit.h"
#include "Iterator.h"
#include "BreadthFirstIterator.h"
#include "DepthFirstIterator.h"
#include <vector>
#include <string>


class FarmLand : public FarmUnit {

public:
	std::vector<FarmUnit*> units;

	FarmLand(const std::string& cropType, double capacity);
	Iterator* createIterator(const std::string& type);
	double getTotalCapacity();
	std::string getCropType();
	
	void add(FarmUnit* unit);
	void remove(FarmUnit* unit);

};

#endif
