//
// Created by klonek on 23.01.20.
//

#include "Maps.h"
#include "FileLoader.h"

std::istream &operator>>(std::istream &in, Maps &map) {
    FileLoader fileLoader;
    in >> map.mapName;
    fileLoader.loadMap(map.mapName, map.tileMap);
    int enemyTypeCount;
    in >> enemyTypeCount;
    for (int j = 0; j < enemyTypeCount; ++j) {
        int enemyCount;
        in >> enemyCount;
        std::string enemyPath;
        in >> enemyPath;
        for (int i = 0; i < enemyCount; ++i) {
            Enemy *enemy = new Enemy;
            fileLoader.loadEnemy(enemyPath, *enemy, map.tileMap);
            map.enemies.push_back(enemy);
        }
    }


    return in;
}
