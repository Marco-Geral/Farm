#include "ExtraBarn.h"

ExtraBarn::ExtraBarn(FarmUnit* unit, double extraCapacity, const std::string& cropType)
    : FieldUpgrades(unit), extraCapacity(extraCapacity), cropType(cropType) {}

void ExtraBarn::upgrade() {
    // Check if the unit is a FarmLand to which we can add barns
    FarmLand* farmLand = dynamic_cast<FarmLand*>(unit);
    if (farmLand) {
        // Create a new barn with the specified crop type and extra capacity
        Barn* newBarn = new Barn(cropType, extraCapacity);  // Use the constructor of Barn

        // Add the new barn as a leaf to the FarmLand
        farmLand->add(newBarn);

        // Optionally, you can log or display the added barn:
        std::cout << "Added new barn with crop type: " << cropType << " and capacity: " << extraCapacity << std::endl;
    } else {
        // If the unit is not a FarmLand, throw an exception or handle the error
        throw std::invalid_argument("ExtraBarn can only be applied to FarmLand.");
    }
}

double ExtraBarn::getLeftoverCapacity() {
    return unit->getTotalCapacity() - unit->getCurrentAmount();
}
