//
// Created by klonek on 21.01.20.
//

#ifndef WIZARDTOWERGAME_FILELOADER_H
#define WIZARDTOWERGAME_FILELOADER_H


#include <string>
#include "TileMap.h"
#include "Enemy.h"

class FileLoader {
public:
    bool loadMap(const std::string path, TileMap &map);

    bool loadEnemys(const std::string path, Enemy &enemy);
};


#endif //WIZARDTOWERGAME_FILELOADER_H
