//
// Created by klonek on 21.01.20.
//

#include <fstream>
#include <iostream>
#include "FileLoader.h"

bool FileLoader::loadMap(const std::string path, TileMap &map) {
    int width;
    int height;
    std::fstream mapFile;
    mapFile.open("../assets/maps/" + path + ".map", std::ios::in);
    if (mapFile.is_open()) {
        mapFile >> width;
        mapFile >> height;
        int level[width * height];
        for (auto &i : level) {
            mapFile >> i;
        }
        std::vector<int> walls;
        int wallCount = 0;
        mapFile >> wallCount;
        for (int j = 0; j < wallCount; ++j) {
            int tmp;
            mapFile >> tmp;
            walls.push_back(tmp);
        }
        std::string texturePath;
        mapFile >> texturePath;
        map = *new TileMap("../assets/textures/" + texturePath, sf::Vector2u(32, 32), level, 40, 40, walls);
        mapFile.close();
        return true;
    } else
        return false;
}

bool FileLoader::loadEnemys(const std::string path, Enemy &enemy) {
    return false;
}
