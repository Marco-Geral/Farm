#include "FieldUpgrades.h"

// Constructor implementation
FieldUpgrades::FieldUpgrades(FarmUnit* unit) : unit(unit) {}

// Delegate to the wrapped unit's getTotalCapacity()
double FieldUpgrades::getTotalCapacity() {
    return unit->getTotalCapacity();
}

// Delegate to the wrapped unit's getCropType()
std::string FieldUpgrades::getCropType() {
    return unit->getCropType();
}
