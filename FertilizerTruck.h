#ifndef FERTILIZERTRUCK_H
#define FERTILIZERTRUCK_H

class FertilizerTruck : Truck {

public:
	CropFields* cropFields;

	void buyTruck();

	void sellTruck();

	void callTruck();

	void startEngine();
};

#endif
