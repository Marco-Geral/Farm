#ifndef FARMUNIT_H
#define FARMUNIT_H
#include "Truck.h"
#include <string>
#include <vector>

class FarmUnit {

protected:
    std::string cropType;
    double capacity;
    double currentAmount;
    std::vector<Truck*> trucks;  // List of trucks observing this unit

public:
    virtual ~FarmUnit() {}
    virtual double getTotalCapacity() = 0;
    virtual std::string getCropType() = 0;

    double getCurrentAmount() const;
    void setCurrentAmount(double amount);

    double getCapacity() const;
    void setCapacity(double cap);

    // Observer-related methods
    void registerTruck(Truck* truck);
    void removeTruck(Truck* truck);
    void notifyTrucks();
};

#endif
