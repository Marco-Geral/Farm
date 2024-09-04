#ifndef FARMLAND_H
#define FARMLAND_H

class FarmLand : FarmUnit {

public:
	vector<FarmUnits*> Units;

	Iterator* createIterator();
};

#endif
