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
    cout << "=====================================================TESTING FARM BASICS================================================" << endl;
    // Create some soil states
    Soil* drySoil = new DrySoil();
    Soil* fruitfulSoil = new FruitfulSoil();

    // Create crop fields
    CropField* cropField1 = new CropField("Wheat", 100.0, drySoil);
    CropField* cropField2 = new CropField("Corn", 150.0, fruitfulSoil);

    // Create barns
    Barn* barn1 = new Barn("Wheat | Sugarcane", 300.0);
    Barn* barn2 = new Barn("Carrots | Onions | Cabbage", 400.0);

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

void testIterator() {
    cout << "=====================================================TESTING ITERATOR================================================" << endl;

    // Create soil states
    Soil* drySoil = new DrySoil();
    Soil* fruitfulSoil = new FruitfulSoil();

    // Create farm units (crop fields and barns)
    CropField* cropField1 = new CropField("Wheat", 100.0, drySoil);
    CropField* cropField2 = new CropField("Corn", 150.0, fruitfulSoil);
    Barn* barn1 = new Barn("Potatoes | Corn | Beans", 200.0);
    Barn* barn2 = new Barn("Beans | Carrots", 300.0);

    // Create farmland and add units
    FarmLand* mainFarm = new FarmLand("Main Farm", 500.0);
    mainFarm->add(cropField1);
    mainFarm->add(cropField2);
    mainFarm->add(barn1);
    mainFarm->add(barn2);

    // Test breadth-first iterator
    std::cout << "Breadth-First Traversal:" << std::endl;
    Iterator* bfsIterator = mainFarm->createIterator("BFS");
    for (bfsIterator->firstFarm(); !bfsIterator->isDone(); bfsIterator->next()) {
        FarmUnit* currentFarm = bfsIterator->currentFarm();
        std::cout << "Crop Type: " << currentFarm->getCropType() << ", Total Capacity: " << currentFarm->getTotalCapacity() << std::endl;
    }

    // Test depth-first iterator
    std::cout << "\nDepth-First Traversal:" << std::endl;
    Iterator* dfsIterator = mainFarm->createIterator("DFS");
    for (dfsIterator->firstFarm(); !dfsIterator->isDone(); dfsIterator->next()) {
        FarmUnit* currentFarm = dfsIterator->currentFarm();
        std::cout << "Crop Type: " << currentFarm->getCropType() << ", Total Capacity: " << currentFarm->getTotalCapacity() << std::endl;
    }

    // Clean up
    delete bfsIterator;
    delete dfsIterator;
    delete mainFarm;
}


void testState() {
    cout << "=====================================================TESTING STATE================================================" << endl;

    // Create crop field with initial DrySoil state
    CropField* cropField = new CropField("Corn", 150.0, new DrySoil());
    cout << "Initial Soil State: " << cropField->getSoilStateName() << endl;
    
    // Set some crops for harvest
    cropField->setCurrentAmount(50.0);
    cout << "Current Amount before any state changes: " << cropField->getCurrentAmount() << endl;

    // Harvest with DrySoil (minimal yield)
    cropField->harvestCrops(cropField);
    cout << "After harvest (DrySoil), Current Amount: " << cropField->getCurrentAmount() << endl;

    // Apply fertilizer and transition to FruitfulSoil (better yield)
    cropField->setSoilState(new FruitfulSoil());
    cout << "After applying fertilizer, Soil State: " << cropField->getSoilStateName() << endl;
    cropField->harvestCrops(cropField);  // Should yield x3 crops
    cout << "After harvest (FruitfulSoil), Current Amount: " << cropField->getCurrentAmount() << endl;

    // Simulate rain (transition to FloodedSoil)
    cropField->rain(cropField);
    cout << "After rain, Soil State: " << cropField->getSoilStateName() << endl;
    
    // Harvest with FloodedSoil (no yield)
    cropField->harvestCrops(cropField);  // Should yield no crops
    cout << "After harvest (FloodedSoil), Current Amount: " << cropField->getCurrentAmount() << endl;
}


void testComposite() {
    cout << "=====================================================TESTING COMPOSITE================================================" << endl;

    // Create farm and fields
    cout << "Creating individual units and printing capacity:" << endl;
    FarmLand* mainFarm = new FarmLand("Main Farm", 1000.0);
    cout << "Total capacity of mainFarm: " << mainFarm->getCapacity() << endl;
    CropField* cropField1 = new CropField("Wheat", 100.0, new DrySoil());
    cout << "Capacity of cropField1: " << cropField1->getCapacity() << endl;
    CropField* cropField2 = new CropField("Corn", 150.0, new FruitfulSoil());
    cout << "Capacity of cropField2: " << cropField2->getCapacity() << endl;
    Barn* barn1 = new Barn("Barn1", 300.0);
    cout << "Capacity of barn1: " << barn1->getCapacity() << endl;
    
    // Add to the farm (composite structure)
    mainFarm->add(cropField1);
    mainFarm->add(cropField2);
    mainFarm->add(barn1);
    
    // Print total capacity of the composite
    cout << "Main Farm Current Capacity: " << mainFarm->getTotalCapacity() << endl;
}

void testDecorator() {
    cout << "=====================================================TESTING DECORATOR================================================" << endl;

    // Create a farm (FarmLand) to which we'll add barns
    FarmLand* mainFarm = new FarmLand("Main Farm", 1000.0);
    CropField* cropField1 = new CropField("Wheat", 100.0, new DrySoil());
    mainFarm->add(cropField1);

    // Display the initial capacity of the farm
    cout << "Initial FarmLand Capacity: " << mainFarm->getTotalCapacity() << endl;

    // Decorate the FarmLand with ExtraBarn (adds 50 units of storage and specifies "Corn" crop type)
    ExtraBarn* barnedFarm = new ExtraBarn(mainFarm, 50.0, "Corn");

    // Perform the upgrade (adding the extra barn to the farmland)
    barnedFarm->upgrade();

    // After the upgrade, show the new capacity and the new barn's crop type
    cout << "FarmLand Capacity after adding Extra Barn: " << barnedFarm->getLeftoverCapacity() << endl;
    
    // Check if a new barn was added and simulate adding crops to it
    cout << "Simulating crop addition to the new barn..." << endl;
    cropField1->setCurrentAmount(80.0);
    cout << "CropField Current Amount: " << cropField1->getCurrentAmount() << endl;

    // Display the current amount and the remaining capacity after crops have been added
    cout << "Remaining capacity after crops are added: " << barnedFarm->getLeftoverCapacity() << endl;
}

void testTruckLogistics() {
    cout << "=====================================================TESTING TRUCK LOGISTICS================================================" << endl;

    // Create a crop field and a barn to register trucks
    Barn* barn = new Barn("General Storage", 200.0);
    CropField* cropField = new CropField("Wheat", 100.0, new DrySoil());
    
    // Create DeliveryTruck and FertilizerTruck, both require a barn
    DeliveryTruck* deliveryTruck = new DeliveryTruck(barn);
    FertilizerTruck* fertilizerTruck = new FertilizerTruck(cropField);

    // Register trucks to the crop field (Observer pattern)
    cropField->registerTruck(deliveryTruck);
    cropField->registerTruck(fertilizerTruck);

    // Trigger events that should notify trucks
    cropField->setCurrentAmount(90.0);
    cout << "DeliveryTruck and FertilizerTruck should have been notified." << endl;

    // Simulate truck operations
    deliveryTruck->startEngine();
    fertilizerTruck->startEngine();

    // Simulate removing trucks
    cropField->removeTruck(deliveryTruck);
    cropField->removeTruck(fertilizerTruck);
}


void testExtraBarnExceptions() {
    cout << "=====================================================TESTING EXTRABARN EXCEPTIONS================================================" << endl;

    try {
        // Attempt to apply ExtraBarn to a CropField (not allowed, should throw exception)
        CropField* cropField = new CropField("Corn", 150.0, new DrySoil());
        ExtraBarn* invalidBarn = new ExtraBarn(cropField, 50.0, "Corn");
        invalidBarn->upgrade();  // Should throw exception

    } catch (const std::invalid_argument& e) {
        cout << "Caught exception: " << e.what() << endl;
    }
}

void testFertilizer() {
    cout << "=====================================================TESTING FERTILIZER================================================" << endl;

    // Create a crop field
    CropField* cropField = new CropField("Corn", 100.0, new DrySoil());
    Fertilizer* fertilizedField = new Fertilizer(cropField);

    // Simulate the fertilizer effect
    fertilizedField->increaseProduction();
    cout << "CropField Capacity after applying fertilizer: " << fertilizedField->getTotalCapacity() << endl;

    // Simulate harvesting crops after applying fertilizer (correct parameter type)
    fertilizedField->harvest(cropField);
    cout << "After harvest, Current Amount: " << cropField->getCurrentAmount() << endl;
}


void testFarmEdgeCases() {
    cout << "=====================================================TESTING FARM EDGE CASES================================================" << endl;

    // Create an empty farmland and test behavior
    FarmLand* emptyFarm = new FarmLand("Empty Farm", 0.0);
    cout << "Empty Farm Capacity: " << emptyFarm->getTotalCapacity() << endl;

    // Try adding a crop field beyond capacity
    CropField* cropField = new CropField("Corn", 150.0, new DrySoil());
    emptyFarm->add(cropField);  // Should not be able to add
    cout << "After trying to add crop field, Farm Capacity: " << emptyFarm->getTotalCapacity() << endl;

    // Test full barn capacity
    Barn* fullBarn = new Barn("Wheat", 100.0);
    fullBarn->setCurrentAmount(100.0);
    cout << "Barn is full: " << (fullBarn->isStorageFull() ? "Yes" : "No") << endl;
}






int main() {
    testFarmStructure();
    testDecorator();
    testComposite();
    testState();
    testIterator();
    cout << endl << "EXTRA TESTING FOR COVERAGE" << endl;
    testTruckLogistics();        
    testExtraBarnExceptions();   
    testFertilizer();            
    testFarmEdgeCases();
    return 0;
}