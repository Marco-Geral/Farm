#ifndef FARMUNIT_H
#define FARMUNIT_H
#include "Iterator.h"
#include "Truck.h"
#include <string>
#include <vector>
#include <algorithm>

class FarmUnit {

protected:
    std::string cropType;
    double capacity;
    double currentAmount;
    std::vector<Truck*> trucks;  // List of trucks observing this unit

public:
    virtual double getTotalCapacity() = 0;
    virtual std::string getCropType() = 0;
    //virtual Iterator* createIterator() = 0;

    double getCurrentAmount() const {
        return currentAmount;
    }

    void setCurrentAmount(double amount) {
        currentAmount = amount;
        notifyTrucks();
    }

    double getCapacity() const {
        return capacity;
    }

    void setCapacity(double cap) {
        capacity = cap;
    }

    // Observer-related methods
    void registerTruck(Truck* truck) {
        trucks.push_back(truck);
    }

    void removeTruck(Truck* truck) {
        // Use the iterator returned by std::remove to call erase on the vector
        trucks.erase(std::remove(trucks.begin(), trucks.end(), truck), trucks.end());
    }

    void notifyTrucks() {
        for (Truck* truck : trucks) {
            truck->callTruck();  // Notify each truck when an event occurs
        }
    }
};

#endif
