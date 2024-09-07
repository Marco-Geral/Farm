#ifndef FERTILIZER_H
#define FERTILIZER_H
#include "FieldUpgrades.h"
#include "CropField.h"
#include "FruitfulSoil.h"
#include "DrySoil.h"

class Fertilizer : public FieldUpgrades {
public:
    Fertilizer(FarmUnit* unit);

    void upgrade() override;  // Transitions from DrySoil to FruitfulSoil
    void increaseProduction();  // Enhances crop yield
    void harvest(CropField* field);
};

#endif
