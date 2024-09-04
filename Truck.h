#ifndef TRUCK_H
#define TRUCK_H

class Truck {


public:
	virtual void buyTruck() = 0;

	virtual void sellTruck() = 0;

	virtual void callTruck() = 0;

	virtual void startEngine() = 0;
};

#endif
