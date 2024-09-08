# Variables
CXX = g++             # Compiler
CXXFLAGS = -std=c++11  # Compiler flags
LDFLAGS =              # Linker flags
OBJS = main.o Barn.o BreadthFirstIterator.o CropField.o DeliveryTruck.o DepthFirstIterator.o DrySoil.o ExtraBarn.o FarmLand.o FarmUnit.o Fertilizer.o FertilizerTruck.o FieldUpgrades.o FloodedSoil.o FruitfulSoil.o Iterator.o Soil.o Truck.o

# Target for the final executable
main: $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o main

# Rule for creating .o (object) files
%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $<

# Special rule for main.o as it includes many header files
main.o: main.cpp Barn.h BreadthFirstIterator.h CropField.h DeliveryTruck.h DepthFirstIterator.h DrySoil.h ExtraBarn.h FarmLand.h FarmUnit.h Fertilizer.h FertilizerTruck.h FieldUpgrades.h FloodedSoil.h FruitfulSoil.h Iterator.h Soil.h Truck.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Clean target to remove generated files
clean:
	rm -f *.o main

# Debug target for debugging symbols
debug: $(OBJS)
	$(CXX) $(CXXFLAGS) -g $(OBJS) -o main

# Target to run the program
run: main
	./main
