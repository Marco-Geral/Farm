#include "Fertilizer.h"
#include <stdexcept>

Fertilizer::Fertilizer(FarmUnit* unit) : FieldUpgrades(unit) {
    if (dynamic_cast<CropField*>(unit) == nullptr) {
        throw std::invalid_argument("Fertilizer can only be applied to a CropField.");
    }
}

void Fertilizer::upgrade() {
    // Call increaseProduction which handles the transition and boost in productivity
    increaseProduction();
}

void Fertilizer::increaseProduction() {
    CropField* field = dynamic_cast<CropField*>(unit);
    if (field && dynamic_cast<DrySoil*>(field->soilState)) {
        // Transition from DrySoil to FruitfulSoil
        field->setSoilState(new FruitfulSoil());
        // Boost productivity (x3 crop yield)
        field->setCurrentAmount(field->getCurrentAmount() + field->getTotalCapacity() * 3);
    }
}
