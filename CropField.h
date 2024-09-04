#ifndef CROPFIELD_H
#define CROPFIELD_H
#include "FarmUnit.h"
#include "Soil.h"

class CropField : FarmUnit {

public:
	Soil* soilState;

	void getSoilStateName();
};

#endif
