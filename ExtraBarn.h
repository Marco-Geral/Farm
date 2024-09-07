#ifndef EXTRABARN_H
#define EXTRABARN_H
#include "FieldUpgrades.h"
#include "Barn.h"
#include "FarmLand.h"
#include <stdexcept>
#include <iostream>

class ExtraBarn : public FieldUpgrades {
    
private:
    double extraCapacity;  // Additional capacity provided by the extra barn
    std::string cropType;  // Crop type for the new barn

public:
    ExtraBarn(FarmUnit* unit, double extraCapacity, const std::string& cropType);

    void upgrade() override;
    double getLeftoverCapacity();
};

#endif
