ZIP_FILE = u23584565.zip
SRC_FILES = $(wildcard *.cpp)

main: main.o Barn.o BreadthFirstIterator.o CropField.o DeliveryTruck.o DepthFirstIterator.o DrySoil.o ExtraBarn.o FarmLand.o FarmUnit.o Fertilizer.o FertilizerTruck.o FieldUpgrades.o FloodedSoil.o FruitfulSoil.o Iterator.o Soil.o Truck.o
	g++ main.o Barn.o BreadthFirstIterator.o CropField.o DeliveryTruck.o DepthFirstIterator.o DrySoil.o ExtraBarn.o FarmLand.o FarmUnit.o Fertilizer.o FertilizerTruck.o FieldUpgrades.o FloodedSoil.o FruitfulSoil.o Iterator.o Soil.o Truck.o -o main

main.o: main.cpp Barn.h BreadthFirstIterator.h CropField.h DeliveryTruck.h DepthFirstIterator.h DrySoil.h ExtraBarn.h FarmLand.h FarmUnit.h Fertilizer.h FertilizerTruck.h FieldUpgrades.h FloodedSoil.h FruitfulSoil.h Iterator.h Soil.h Truck.h
	g++ -std=c++11 -c main.cpp

Barn.o: Barn.cpp Barn.h FarmUnit.h
	g++ -std=c++11 -c Barn.cpp

BreadthFirstIterator.o: BreadthFirstIterator.cpp BreadthFirstIterator.h Iterator.h FarmLand.h
	g++ -std=c++11 -c BreadthFirstIterator.cpp

CropField.o: CropField.h CropField.cpp FarmUnit.h Soil.h DrySoil.h
	g++ -std=c++11 -c CropField.cpp

DeliveryTruck.o: DeliveryTruck.h DeliveryTruck.cpp Truck.h Barn.h
	g++ -std=c++11 -c DeliveryTruck.cpp

DepthFirstIterator.o: DepthFirstIterator.cpp DepthFirstIterator.h Iterator.h FarmLand.h
	g++ -std=c++11 -c DepthFirstIterator.cpp

DrySoil.o: DrySoil.h DrySoil.cpp Soil.h CropField.h FruitfulSoil.h
	g++ -std=c++11 -c DrySoil.cpp

ExtraBarn.o: ExtraBarn.h ExtraBarn.cpp Barn.h FarmLand.h FieldUpgrades.h
	g++ -std=c++11 -c ExtraBarn.cpp

FarmLand.o: FarmLand.h FarmLand.cpp FarmUnit.h Iterator.h BreadthFirstIterator.h DepthFirstIterator.h
	g++ -std=c++11 -c FarmLand.cpp

FarmUnit.o: FarmUnit.h FarmUnit.cpp Truck.h
	g++ -std=c++11 -c FarmUnit.cpp

Fertilizer.o: Fertilizer.h Fertilizer.cpp FieldUpgrades.h CropField.h FruitfulSoil.h DrySoil.h
	g++ -std=c++11 -c Fertilizer.cpp

FertilizerTruck.o: FertilizerTruck.h FertilizerTruck.cpp Truck.h CropField
	g++ -std=c++11 -c FertilizerTruck.cpp

FieldUpgrades.o: FieldUpgrades.h FieldUpgrades.cpp FarmUnit.h
	g++ -c FieldUpgrades.cpp

FloodedSoil.o: FloodedSoil.h FloodedSoil.cpp Soil.h CropField.h
	g++ -std=c++11 -c FloodedSoil.cpp

FruitfulSoil.o: FruitfulSoil.h FruitfulSoil.cpp Soil.h CropField.h FloodedSoil.h
	g++ -std=c++11 -c FruitfulSoil.cpp

run: main
	./main

clean:
	rm -f *.o main main.exe

zip:
	zip -u $(ZIP_FILE) $(SRC_FILES) *.h Makefile

debugcpp: debugo
	g++ -ggdb3 -o main *.o

debugo: *.cpp
	g++ -ggdb3 -c -w *.cpp

v:
	make debugcpp
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes --log-file=valg.txt ./main
	make clean
