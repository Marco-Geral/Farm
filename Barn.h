#ifndef BARN_H
#define BARN_H

class Barn : FarmUnit {

private:
	ENUM cropType;
	double capacity;

public:
	ENUM getCropType();

	double getTotalCapacity();
};

#endif
