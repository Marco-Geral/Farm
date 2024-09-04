#ifndef FARMUNIT_H
#define FARMUNIT_H
#include "Iterator.h"
#include <string>

class FarmUnit {

private:
	std::string cropType;
	double capacity;

public:
	double getTotalCapacity();

	std::string getCropType();

	Iterator* createIterator();
};

#endif
