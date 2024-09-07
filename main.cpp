#include <iostream>
#include "Barn.h"
#include "BreadthFirstIterator.h"
#include "CropField.h"
#include "DeliveryTruck.h"
#include "DepthFirstIterator.h"
#include "DrySoil.h"
#include "ExtraBarn.h"
#include "FarmLand.h"
#include "FarmUnit.h"
#include "Fertilizer.h"
#include "FertilizerTruck.h"
#include "FieldUpgrades.h"
#include "FloodedSoil.h"
#include "FruitfulSoil.h"
#include "Iterator.h"
#include "Soil.h"
#include "Truck.h"
using namespace std;

void testFarmStructure() {
    // Create some soil states
    Soil* drySoil = new DrySoil();
    Soil* fruitfulSoil = new FruitfulSoil();

    // Create crop fields
    CropField* cropField1 = new CropField("Wheat", 100.0, drySoil);
    CropField* cropField2 = new CropField("Corn", 150.0, fruitfulSoil);

    // Create barns
    Barn* barn1 = new Barn("Barn1", 300.0);
    Barn* barn2 = new Barn("Barn2", 400.0);

    // Create the main farm and add units to it
    FarmLand* mainFarm = new FarmLand("Main Farm", 1000.0);
    mainFarm->add(cropField1);
    mainFarm->add(cropField2);
    mainFarm->add(barn1);
    mainFarm->add(barn2);

    // Print farm details
    std::cout << "Farm Details:" << std::endl;
    std::cout << "Total Capacity: " << mainFarm->getTotalCapacity() << std::endl;
    std::cout << "Crop Types: " << mainFarm->getCropType() << std::endl;

    // Print details of each crop field and its soil state
    std::cout << "Crop Field 1 - Type: " << cropField1->getCropType() << ", Capacity: " << cropField1->getTotalCapacity() << ", Soil State: " << cropField1->getSoilStateName() << std::endl;
    std::cout << "Crop Field 2 - Type: " << cropField2->getCropType() << ", Capacity: " << cropField2->getTotalCapacity() << ", Soil State: " << cropField2->getSoilStateName() << std::endl;

    // Test barn storage
    std::cout << "Barn 1 - Crop Type: " << barn1->getCropType() << ", Capacity: " << barn1->getTotalCapacity() << std::endl;
    std::cout << "Barn 2 - Crop Type: " << barn2->getCropType() << ", Capacity: " << barn2->getTotalCapacity() << std::endl;

    // Simulate adding crops to a barn and checking if it's nearing capacity
    barn1->setCurrentAmount(250.0);
    std::cout << "Barn 1 - Current Amount: " << barn1->getCurrentAmount() << ", Is Storage Full? " << (barn1->isStorageFull() ? "Yes" : "No") << std::endl;

    // Simulate adding crops to CropField1 and harvesting
    cropField1->setCurrentAmount(80.0);
    std::cout << "Crop Field 1 - Current Amount: " << cropField1->getCurrentAmount() << std::endl;
    cropField1->harvestCrops(cropField1);  // Harvest crops based on soil state
    std::cout << "Crop Field 1 - After Harvest, Current Amount: " << cropField1->getCurrentAmount() << std::endl;
}

int main() {
    testFarmStructure();
    return 0;
}