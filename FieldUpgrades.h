#ifndef FIELDUPGRADES_H
#define FIELDUPGRADES_H

class FieldUpgrades {

private:
	FarmUnits* Pieces;

public:
	virtual void upgrade() = 0;
};

#endif
