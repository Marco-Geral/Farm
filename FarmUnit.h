#ifndef FARMUNIT_H
#define FARMUNIT_H

class FarmUnit {

private:
	ENUM cropType;
	double capacity;

public:
	double getTotalCapacity();

	ENUM getCropType();

	Iterator* createIterator();
};

#endif
