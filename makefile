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
	rm -f PlayerTest

# Build and run MeleeEnemy test

test_MeleeEnemy:
	$(CXX) $(CXXFLAGS) -c MeleeEnemyTest_main.cpp

	$(CXX) $(CXXFLAGS) -c RoomObject.cpp

	$(CXX) $(CXXFLAGS) -c Projectile.cpp

	$(CXX) $(CXXFLAGS) -c Entity.cpp

	$(CXX) $(CXXFLAGS) -c Enemy.cpp

	$(CXX) $(CXXFLAGS) -c MeleeEnemy.cpp

	$(CXX) MeleeEnemyTest_main.o RoomObject.o Projectile.o Entity.o Enemy.o MeleeEnemy.o -o MeleeEnemyTest $(SFML)

	./MeleeEnemyTest

# Clean Player test

clean_test_MeleeEnemy:
	rm -f MeleeEnemyTest_main.o
	rm -f RoomObject.o
	rm -f Projectile.o
	rm -f Entity.o
	rm -f Enemy.o
	rm -f MeleeEnemy.o
	rm -f MeleeEnemyTest

# Build and run all files

build_all:

	$(CXX) $(CXXFLAGS) -c ArrowTrap.cpp

	$(CXX) $(CXXFLAGS) -c BasicBoss.cpp

	$(CXX) $(CXXFLAGS) -c DungeonFloor.cpp

	$(CXX) $(CXXFLAGS) -c Room.cpp

	$(CXX) $(CXXFLAGS) -c Enemy.cpp

	$(CXX) $(CXXFLAGS) -c Entity.cpp

	$(CXX) $(CXXFLAGS) -c HealthConsumable.cpp

	$(CXX) $(CXXFLAGS) -c MeleeEnemy.cpp

	$(CXX) $(CXXFLAGS) -c SpikeTrap.cpp

	$(CXX) $(CXXFLAGS) -c StrikerEnemy.cpp

	$(CXX) $(CXXFLAGS) -c StrikerTarget.cpp

	$(CXX) $(CXXFLAGS) -c Tile.cpp

	$(CXX) $(CXXFLAGS) -c Trap.cpp

	$(CXX) $(CXXFLAGS) -c RoomObject.cpp

	$(CXX) $(CXXFLAGS) -c Projectile.cpp

	$(CXX) $(CXXFLAGS) -c Entity.cpp

	$(CXX) $(CXXFLAGS) -c Player.cpp

	$(CXX) $(CXXFLAGS) -c main.cpp

	$(CXX) main.o DungeonFloor.o Room.o Tile.o RoomObject.o Entity.o Projectile.o Trap.o SpikeTrap.o ArrowTrap.o Player.o Enemy.o MeleeEnemy.o StrikerEnemy.o StrikerTarget.o BasicBoss.o HealthConsumable.o -o game $(SFML)

	./game
	
# Clean all files

clean_all:
	rm -f main.o
	rm -f DungeonFloor.o
	rm -f Room.o
	rm -f Tile.o
	rm -f RoomObject.o
	rm -f Entity.o
	rm -f Projectile.o
	rm -f Trap.o
	rm -f SpikeTrap.o
	rm -f ArrowTrap.o
	rm -f Player.o
	rm -f Enemy.o
	rm -f MeleeEnemy.o
	rm -f StrikerEnemy.o
	rm -f StrikerTarget.o
	rm -f BasicBoss.o
	rm -f HealthConsumable.o
	rm -f game