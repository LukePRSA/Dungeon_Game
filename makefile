# Compiler

CXX = g++

# Compiler flags

CXXFLAGS = -Wall -Wextra

# SFML library flags

SFML = -lsfml-graphics -lsfml-window -lsfml-system

# Build and run RoomObject test

test_RoomObject:
	$(CXX) $(CXXFLAGS) -c RoomObjectTest_main.cpp

	$(CXX) $(CXXFLAGS) -c RoomObject.cpp

	$(CXX) RoomObjectTest_main.o RoomObject.o -o RoomObjectTest $(SFML)

	./RoomObjectTest

# Clean RoomObject test

clean_test_RoomObject:
	rm -f RoomObjectTest_main.o
	rm -f RoomObject.o
	rm -f RoomObjectTest

# Build and run Entity test

test_Entity:
	$(CXX) $(CXXFLAGS) -c EntityTest_main.cpp

	$(CXX) $(CXXFLAGS) -c RoomObject.cpp

	$(CXX) $(CXXFLAGS) -c Entity.cpp

	$(CXX) EntityTest_main.o RoomObject.o Entity.o -o EntityTest $(SFML)

	./EntityTest

# Clean Entity test

clean_test_Entity:
	rm -f EntityTest_main.o
	rm -f RoomObject.o
	rm -f Entity.o
	rm -f EntityTest