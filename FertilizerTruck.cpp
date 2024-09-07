#include "FertilizerTruck.h"
#include <iostream>

FertilizerTruck::FertilizerTruck(CropField* field) : cropField(field) {}

void FertilizerTruck::buyTruck() {
    std::cout << "Buying a Fertilizer Truck." << std::endl;
    // Logic to purchase a fertilizer truck
}

void FertilizerTruck::sellTruck() {
    std::cout << "Selling the Fertilizer Truck." << std::endl;
    // Logic to sell the truck
}

void FertilizerTruck::callTruck() {
    // Check if the crop field needs fertilization
    if (cropField->needsFertilization()) {
		std::cout << "Calling a Fertilizer Truck" << std::endl;
        startEngine();
    }
}

void FertilizerTruck::startEngine() {
    // Logic to deliver fertilizer to the crop field
    std::cout << "Fertilizer Truck delivering to field: " << cropField->getCropType() << std::endl;
}
