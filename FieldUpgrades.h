#ifndef FIELDUPGRADES_H
#define FIELDUPGRADES_H
#include "FarmUnit.h"

class FieldUpgrades : public FarmUnit {  // Inherit from FarmUnit to act as a decorator

protected:
    FarmUnit* unit;  // Composition: FieldUpgrades wraps a FarmUnit

public:
    FieldUpgrades(FarmUnit* unit) : unit(unit) {}  // Constructor to set the component

    // Delegate existing functionality to the wrapped unit
    double getTotalCapacity() override {
        return unit->getTotalCapacity();
    }

    std::string getCropType() override {
        return unit->getCropType();
    }

    virtual void upgrade() = 0;  // Abstract upgrade function for decorators
};

#endif
