#include "DeliveryTruck.h"
#include <iostream>

DeliveryTruck::DeliveryTruck(Barn* barn) : barn(barn) {}

void DeliveryTruck::buyTruck() {
    std::cout << "Buying a Delivery Truck." << std::endl;
    // Logic to purchase a delivery truck
}

void DeliveryTruck::sellTruck() {
    std::cout << "Selling the Delivery Truck." << std::endl;
    // Logic to sell the truck
}

void DeliveryTruck::callTruck() {
    // Check if the barn’s storage is nearing capacity
    if (barn->isStorageFull()) {
		std::cout << "Calling a Delivery Truck" << std::endl;
        startEngine();
    }
}

void DeliveryTruck::startEngine() {
    // Logic to collect harvested crops from the barn
    std::cout << "Delivery Truck collecting crops from barn: " << barn->getCropType() << std::endl;
}
