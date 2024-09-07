ZIP_FILE = u23584565.zip
SRC_FILES = $(wildcard *.cpp)

TestingMain: TestingMain.o Barn.o BreadthFirstIterator.o CropField.o DeliveryTruck.o DepthFirstIterator.o DrySoil.o ExtraBarn.o FarmLand.o FarmUnit.o Fertilizer.o FertilizerTruck.o FieldUpgrades.o FloodedSoil.o FruitfulSoil.o Iterator.o Soil.o Truck.o
	g++ TestingMain.o Barn.o BreadthFirstIterator.o CropField.o DeliveryTruck.o DepthFirstIterator.o DrySoil.o ExtraBarn.o FarmLand.o FarmUnit.o Fertilizer.o FertilizerTruck.o FieldUpgrades.o FloodedSoil.o FruitfulSoil.o Iterator.o Soil.o Truck.o -o TestingMain

TestingMain.o: TestingMain.cpp Barn.h BreadthFirstIterator.h CropField.h DeliveryTruck.h DepthFirstIterator.h DrySoil.h ExtraBarn.h FarmLand.h FarmUnit.h Fertilizer.h FertilizerTruck.h FieldUpgrades.h FloodedSoil.h FruitfulSoil.h Iterator.h Soil.h Truck.h
	g++ -c TestingMain.cpp

Barn.o: Barn.cpp Barn.h FarmUnit.h
	g++ -c Barn.cpp

BreadthFirstIterator.o: BreadthFirstIterator.cpp BreadthFirstIterator.h Iterator.h FarmLand.h
	g++ -c BreadthFirstIterator.cpp

CropField.o: CropField.h CropField.cpp LegionFactory.h FarmUnit.h Soil.h DrySoil.h
	g++ -c CropField.cpp

DeliveryTruck.o: DeliveryTruck.h DeliveryTruck.cpp Truck.h Barn.h
	g++ -c DeliveryTruck.cpp

DepthFirstIterator.o: DepthFirstIterator.cpp DepthFirstIterator.h Iterator.h FarmLand.h
	g++ -c DepthFirstIterator.cpp

DrySoil.o: DrySoil.h DrySoil.cpp Soil.h CropField.h FruitfulSoil.h
	g++ -c DrySoil.cpp

ExtraBarn.o: ExtraBarn.h ExtraBarn.cpp Barn.h FarmLand.h FieldUpgrades.h
	g++ -c ExtraBarn.cpp

FarmLand.o: FarmLand.h FarmLand.cpp FarmUnit.h Iterator.h BreadthFirstIterator.h DepthFirstIterator.h
	g++ -c FarmLand.cpp

FarmUnit.o: FarmUnit.h FarmUnit.cpp Truck.h
	g++ -c FarmUnit.cpp

Fertilizer.o: Fertilizer.h Fertilizer.cpp FieldUpgrades.h CropField.h FruitfulSoil.h DrySoil.h
	g++ -c Fertilizer.cpp

FertilizerTruck.o: FertilizerTruck.h FertilizerTruck.cpp Truck.h CropField
	g++ -c FertilizerTruck.cpp

FieldUpgrades.o: FieldUpgrades.h FieldUpgrades.cpp FarmUnit.h
	g++ -c FieldUpgrades.cpp

FloodedSoil.o: FloodedSoil.h FloodedSoil.cpp Soil.h CropField.h
	g++ -c FloodedSoil.cpp

FruitfulSoil.o: FruitfulSoil.h FruitfulSoil.cpp Soil.h CropField.h FloodedSoil.h
	g++ -c FruitfulSoil.cpp

run: TestingMain
	./TestingMain

clean:
	rm -f *.o TestingMain TestingMain.exe

zip:
	zip -u $(ZIP_FILE) $(SRC_FILES) *.h Makefile

debugcpp: debugo
	g++ -ggdb3 -o TestingMain *.o

debugo: *.cpp
	g++ -ggdb3 -c -w *.cpp

v:
	make debugcpp
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes --log-file=valg.txt ./TestingMain
	make clean
