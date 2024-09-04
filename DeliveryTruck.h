#ifndef DELIVERYTRUCK_H
#define DELIVERYTRUCK_H
#include "Truck.h"
#include "Barn.h"

class DeliveryTruck : Truck {

public:
	Barn* harvestedCrops;

	void buyTruck();

	void startEngine();

	void sellTruck();

	void callTruck();
};

#endif
