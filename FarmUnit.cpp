#include "FarmUnit.h"
#include <algorithm>

double FarmUnit::getCurrentAmount() const {
    return currentAmount;
}

void FarmUnit::setCurrentAmount(double amount) {
    currentAmount = amount;
    notifyTrucks();  // Notify trucks when the current amount changes
}

double FarmUnit::getCapacity() const {
    return capacity;
}

void FarmUnit::setCapacity(double cap) {
    capacity = cap;
}

void FarmUnit::registerTruck(Truck* truck) {
    trucks.push_back(truck);
}

void FarmUnit::removeTruck(Truck* truck) {
    // Use the iterator returned by std::remove to call erase on the vector
    trucks.erase(std::remove(trucks.begin(), trucks.end(), truck), trucks.end());
}

void FarmUnit::notifyTrucks() {
    for (Truck* truck : trucks) {
        truck->callTruck();  // Notify each truck when an event occurs
    }
}
