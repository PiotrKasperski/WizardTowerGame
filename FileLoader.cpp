

#include <fstream>
#include <iostream>
#include <random>
#include "FileLoader.h"

bool FileLoader::loadMap(const std::string path, TileMap &map) {
    std::fstream mapFile;
    mapFile.open("../assets/maps/" + path + ".map", std::ios::in);
    if (mapFile.is_open()) {
        int width;
        int height;
        mapFile >> width;
        mapFile >> height;
        int level[width * height];
        for (auto &i : level) {
            mapFile >> i;
            i -= 1;
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
        map = *new TileMap("../assets/textures/" + texturePath, sf::Vector2u(32, 32), level, width, height, walls);
        mapFile.close();
        return true;
    } else
        return false;
}

bool FileLoader::loadEnemy(const std::string path, Enemy &enemy, TileMap &tileMap) {
    std::fstream enemyFile;
    enemyFile.open("../assets/enemy/" + path + ".enemy", std::ios::in);
    if (enemyFile.is_open()) {
        //enemy = *new Enemy();
        enemyFile >> enemy;
        enemy.setPosition(FileLoader::randomizePosition(tileMap));
        std::vector<CollisionObject *> tMap;
        tMap.push_back(&tileMap);
        while (enemy.isCollision(tMap)) {
            enemy.setPosition(FileLoader::randomizePosition(tileMap));
        }
        enemyFile.close();
        return true;
    } else
        return false;
}

bool FileLoader::loadStory(const std::string path, Story &story) {
    std::fstream storyFile;
    storyFile.open("../assets/" + path + ".story", std::ios::in);
    if (storyFile.is_open()) {
        storyFile >> story;
        storyFile.close();
        return true;
    } else
    return false;
}

bool FileLoader::loadQuest(std::string path, Quest &quest) {
    return false;
}

sf::Vector2f FileLoader::randomizePosition(TileMap &tileMap) {
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> randWidth(0, tileMap.getWidth());
    std::uniform_int_distribution<> randHeight(0, tileMap.getHeight());

    int x = (randWidth(gen)) * 32;
    int y = (randHeight(gen)) * 32;
    return sf::Vector2f(x, y);
}

