#ifndef FARMUNIT_H
#define FARMUNIT_H
#include "Iterator.h"
#include <string>

class FarmUnit {

private:
	std::string cropType;
	double capacity;

public:
	virtual double getTotalCapacity() = 0;

	virtual std::string getCropType() = 0;

	virtual Iterator* createIterator() = 0;
};

#endif
