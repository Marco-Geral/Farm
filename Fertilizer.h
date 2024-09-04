#ifndef FERTILIZER_H
#define FERTILIZER_H

class Fertilizer : FieldUpgrades {

public:
	FruitfulSoil newSoil;

	void harvest();

	void increaseProduction();

	void upgrade();
};

#endif
