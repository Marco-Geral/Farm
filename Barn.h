#ifndef BARN_H
#define BARN_H
#include "FarmUnit.h"
#include <string>

class Barn : public FarmUnit {

public:

	Barn(const std::string& cropType, double capacity);
	std::string getCropType();
	double getTotalCapacity();

	bool isStorageFull();
};

#endif
