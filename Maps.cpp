//
// Created by klonek on 23.01.20.
//

#include "Maps.h"
#include "FileLoader.h"

std::istream &operator>>(std::istream &in, Maps &map) {
    FileLoader fileLoader;
    in >> map.mapName;
    map.tileMap = new TileMap;
    fileLoader.loadMap(map.mapName, *map.tileMap);
    int doorCount;
    in >> doorCount;
    for (int k = 0; k < doorCount; ++k) {
        auto *door = new Door;
        in >> *door;
        map.doors.push_back(door);
    }


    int enemyTypeCount;
    in >> enemyTypeCount;
    for (int j = 0; j < enemyTypeCount; ++j) {
        int enemyCount;
        in >> enemyCount;
        std::string enemyPath;
        in >> enemyPath;
        for (int i = 0; i < enemyCount; ++i) {
            Enemy *enemy = new Enemy;
            fileLoader.loadEnemy(enemyPath, *enemy, *map.tileMap);
            map.enemies.push_back(enemy);
        }
    }


    return in;
}

Maps::Maps(const std::string &mapName) : mapName(mapName) {
    auto *enemy1 = new Enemy(sf::Vector2f(64.0f, 2 * 96.0f), "../assets/textures/character.png",
                             sf::IntRect(32, 64, 32, 32));
    auto *enemy2 = new Enemy(sf::Vector2f(5 * 64.0f, 4 * 96.0f), "../assets/textures/character.png",
                             sf::IntRect(32, 64, 32, 32));
    this->enemies.push_back(enemy1);
    this->enemies.push_back(enemy2);

    auto *door = new Door(sf::FloatRect(sf::Vector2f(39 * 32.0f, 1 * 32.0f), sf::Vector2f(64.0f, 96.0f)), "first",
                          sf::Vector2f(32.0f, 64.0f));
    this->doors.push_back(door);
}

TileMap *Maps::getTileMap() const {
    return tileMap;
}

std::vector<Enemy *> &Maps::getEnemies() {
    return enemies;
}

const std::vector<Door *> &Maps::getDoors() const {
    return doors;
}

const std::string &Maps::getMapName() const {
    return mapName;
}

Maps::Maps() {}
