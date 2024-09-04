#ifndef EXTRABARN_H
#define EXTRABARN_H
#include "FieldUpgrades.h"

class ExtraBarn : FieldUpgrades {


public:
	virtual void upgrade() = 0;

	double getLeftoverCapacity();
};

#endif
