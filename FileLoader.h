

#ifndef WIZARDTOWERGAME_FILELOADER_H
#define WIZARDTOWERGAME_FILELOADER_H


#include <string>
#include "TileMap.h"
#include "Enemy.h"
#include "Story.h"

class FileLoader {
public:
    bool loadMap(const std::string path, TileMap &map);

    bool loadEnemy(const std::string path, Enemy &enemy, TileMap &tileMap);

    bool loadStory(const std::string path, Story &story);

    bool loadQuest(std::string path, Quest &quest);

private:
    sf::Vector2f randomizePosition(TileMap &);
};


#endif //WIZARDTOWERGAME_FILELOADER_H
