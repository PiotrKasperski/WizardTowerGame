//
// Created by klonek on 23.01.20.
//

#ifndef WIZARDTOWERGAME_MAPS_H
#define WIZARDTOWERGAME_MAPS_H


#include <vector>
#include "Enemy.h"
#include "TileMap.h"

class Maps {
    std::string mapName;
    TileMap tileMap;
    std::vector<Enemy *> enemies;
};


#endif //WIZARDTOWERGAME_MAPS_H
