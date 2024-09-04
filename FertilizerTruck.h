#ifndef FERTILIZERTRUCK_H
#define FERTILIZERTRUCK_H
#include "Truck.h"
#include "CropField.h"

class FertilizerTruck : Truck {

public:
	CropField* cropFields;

	void buyTruck();

	void sellTruck();

	void callTruck();

	void startEngine();
};

#endif
