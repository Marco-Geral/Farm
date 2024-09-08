# Variables
CXX = g++             # Compiler
CXXFLAGS = -std=c++11  # Compiler flags
LDFLAGS =              # Linker flags
OBJS = TestingMain.o Barn.o BreadthFirstIterator.o CropField.o DeliveryTruck.o DepthFirstIterator.o DrySoil.o ExtraBarn.o FarmLand.o FarmUnit.o Fertilizer.o FertilizerTruck.o FieldUpgrades.o FloodedSoil.o FruitfulSoil.o
ZIPFILE = u23590051.zip  # Name of the zip file
SRC = *.cpp *.h Makefile  # Source files and headers to include in the zip

# Target for the final executable
TestingMain: $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o TestingMain

# Rule for creating .o (object) files
%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $<

# Special rule for TestingMain.o as it includes many header files
TestingMain.o: TestingMain.cpp Barn.h BreadthFirstIterator.h CropField.h DeliveryTruck.h DepthFirstIterator.h DrySoil.h ExtraBarn.h FarmLand.h FarmUnit.h Fertilizer.h FertilizerTruck.h FieldUpgrades.h FloodedSoil.h FruitfulSoil.h Iterator.h Soil.h Truck.h
	$(CXX) $(CXXFLAGS) -c TestingMain.cpp

# Clean target to remove generated files
clean:
	rm -f *.o TestingMain

# Debug target for debugging symbols
debug: $(OBJS)
	$(CXX) $(CXXFLAGS) -g $(OBJS) -o TestingMain

# Target to run the program
run: TestingMain
	./TestingMain

# Zip target to compress relevant files into a zip archive
zip:
	zip -r $(ZIPFILE) $(SRC)
