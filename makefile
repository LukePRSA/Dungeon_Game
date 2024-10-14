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

# Build and run Projectile test

test_Projectile:
	$(CXX) $(CXXFLAGS) -c ProjectileTest_main.cpp

	$(CXX) $(CXXFLAGS) -c RoomObject.cpp

	$(CXX) $(CXXFLAGS) -c Projectile.cpp

	$(CXX) ProjectileTest_main.o RoomObject.o Projectile.o -o ProjectileTest $(SFML)

	./ProjectileTest

# Clean Projectile test

clean_test_Projectile:
	rm -f ProjectileTest_main.o
	rm -f RoomObject.o
	rm -f Projectile.o
	rm -f ProjectileTest

# Build and run Player test

test_Player:
	$(CXX) $(CXXFLAGS) -c PlayerTest_main.cpp

	$(CXX) $(CXXFLAGS) -c RoomObject.cpp

	$(CXX) $(CXXFLAGS) -c Projectile.cpp

	$(CXX) $(CXXFLAGS) -c Entity.cpp

	$(CXX) $(CXXFLAGS) -c Player.cpp

	$(CXX) PlayerTest_main.o RoomObject.o Projectile.o Entity.o Player.o -o PlayerTest $(SFML)

	./PlayerTest

# Clean Player test

clean_test_Player:
	rm -f PlayerTest_main.o
	rm -f RoomObject.o
	rm -f Projectile.o
	rm -f Entity.o
	rm -f Player.o