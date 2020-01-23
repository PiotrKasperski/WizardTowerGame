//
// Created by klonek on 23.01.20.
//

#ifndef WIZARDTOWERGAME_STORY_H
#define WIZARDTOWERGAME_STORY_H


#include "Maps.h"
#include "Quest.h"
#include "Player.h"

class Story {
private:
    std::vector<Maps *> maps;
    std::vector<Quest *> quests;
    Maps *currentMap;
    Player *player;

    void kill(std::vector<FightingObject *> &fightingObjects);

    void levelUp();

    void changeMap();

public:
    Story();

    Player *getPlayer() const;

    void loadCurrentMap(std::vector<RendererObject *> &rendererObject,
                        std::vector<MovableObjects *> &movableObjects,
                        std::vector<CollisionObject *> &collisionObject,
                        std::vector<FightingObject *> &fightingObjects);

    void Update(std::vector<RendererObject *> &rendererObject,
                std::vector<MovableObjects *> &movableObjects,
                std::vector<CollisionObject *> &collisionObject,
                std::vector<FightingObject *> &fightingObjects);



};


#endif //WIZARDTOWERGAME_STORY_H
