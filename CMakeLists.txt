cmake_minimum_required(VERSION 3.14)
project(WizardTowerGame)

set(CMAKE_CXX_STANDARD 14)

#add SFML lib
set(SFML_INCLUDE_DIR "/home/rewieer/Libraries/SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "/home/rewieer/Libraries/SFML-2.5.1/lib")
set(SFML_DIR "/home/rewieer/Libraries/SFML-2.5.1/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if (SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif ()

add_executable(WizardTowerGame main.cpp Game.cpp Game.h Engine.cpp Engine.h Player.cpp Player.h RendererObject.cpp RendererObject.h MovableObjects.cpp MovableObjects.h TileMap.cpp TileMap.h CollisionObject.cpp CollisionObject.h Interface/Camera.cpp Interface/Camera.h Enemy.cpp Enemy.h FileLoader.cpp FileLoader.h Staticstics.cpp Staticstics.h FightingObject.cpp FightingObject.h Quest.cpp Quest.h Maps.cpp Maps.h Story.cpp Story.h Door.cpp Door.h Equipment/Equipment.cpp Equipment/Equipment.h Interface.cpp Interface.h Interface/Hud/Hud.cpp Interface/Hud/Hud.h Interface/InventoryGui/InventoryGui.cpp Interface/InventoryGui/InventoryGui.h Interface/StatsGui/StatsGui.cpp Interface/StatsGui/StatsGui.h Interface/LootGui/LootGui.cpp Interface/LootGui/LootGui.h Equipment/Projectile.cpp Equipment/Projectile.h Equipment/Weapon.cpp Equipment/Weapon.h Equipment/Armor.cpp Equipment/Armor.h FightMenager.cpp FightMenager.h MainMenu.cpp MainMenu.h)


target_link_libraries(WizardTowerGame sfml-graphics sfml-window sfml-system)

