#ifndef DELIVERYTRUCK_H
#define DELIVERYTRUCK_H
#include "Truck.h"
#include "Barn.h"

class DeliveryTruck : public Truck {

public:
    Barn* barn;

    DeliveryTruck(Barn* barn);  // Constructor

    void buyTruck() override;
    void sellTruck() override;
    void callTruck() override;
    void startEngine() override;
};

#endif
