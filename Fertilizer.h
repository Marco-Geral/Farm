#ifndef FERTILIZER_H
#define FERTILIZER_H
#include "FieldUpgrades.h"
#include "FruitfulSoil.h"

class Fertilizer : FieldUpgrades {

public:
	FruitfulSoil newSoil;

	void harvest();

	void increaseProduction();

	void upgrade();
};

#endif
