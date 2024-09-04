#ifndef FIELDUPGRADES_H
#define FIELDUPGRADES_H
#include "FarmUnit.h"

class FieldUpgrades {

private:
	FarmUnit* Pieces;

public:
	virtual void upgrade() = 0;
};

#endif
