//
// Created by klonek on 23.01.20.
//

#ifndef WIZARDTOWERGAME_MAPS_H
#define WIZARDTOWERGAME_MAPS_H


#include <vector>
#include "Enemy.h"
#include "TileMap.h"
#include "Door.h"

class Maps {
private:
    std::string mapName;
    TileMap *tileMap;
    std::vector<Enemy *> enemies;
public:
    friend std::istream &operator>>(std::istream &in, Maps &map);
    std::vector<Door *> doors;
public:
    TileMap *getTileMap() const;

    std::vector<Enemy *> &getEnemies();

    const std::vector<Door *> &getDoors() const;

    Maps(const std::string &mapName, const TileMap &tileMap, const std::vector<Enemy *> &enemies);

    Maps(const std::string &mapName);

    Maps();

    const std::string &getMapName() const;
};



#endif //WIZARDTOWERGAME_MAPS_H
