#ifndef FERTILIZERTRUCK_H
#define FERTILIZERTRUCK_H
#include "Truck.h"
#include "CropField.h"

class FertilizerTruck : public Truck {

public:
    CropField* cropField;

    FertilizerTruck(CropField* field);  // Constructor

    void buyTruck() override;
    void sellTruck() override;
    void callTruck() override;
    void startEngine() override;
};

#endif
