//
// Created by klonek on 23.01.20.
//

#ifndef WIZARDTOWERGAME_QUEST_H
#define WIZARDTOWERGAME_QUEST_H


#include "Enemy.h"

class Quest {
    enum questType {
        KILL, FIND
    };
    int experience;
    int questCount;
    std::string questDescription;
    std::string questName;
    std::string enemyToKillName;

};


#endif //WIZARDTOWERGAME_QUEST_H
