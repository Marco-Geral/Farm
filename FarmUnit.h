#ifndef FARMUNIT_H
#define FARMUNIT_H
#include "Iterator.h"
#include <string>

class FarmUnit {

protected:
    std::string cropType;
    double capacity;
    double currentAmount;

public:
    virtual double getTotalCapacity() = 0;
    virtual std::string getCropType() = 0;
    virtual Iterator* createIterator() = 0;

    double getCurrentAmount() const {
        return currentAmount;
    }

    void setCurrentAmount(double amount) {
        currentAmount = amount;
    }
};

#endif
