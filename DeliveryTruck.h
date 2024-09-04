#ifndef DELIVERYTRUCK_H
#define DELIVERYTRUCK_H

class DeliveryTruck : Truck {

public:
	Barn* harvestedCrops;

	void buyTruck();

	void startEngine();

	void sellTruck();

	void callTruck();
};

#endif
