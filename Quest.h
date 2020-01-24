//
// Created by klonek on 23.01.20.
//

#ifndef WIZARDTOWERGAME_QUEST_H
#define WIZARDTOWERGAME_QUEST_H


#include "Enemy.h"

class Quest {
private:
    enum questType {
        KILL, FIND
    };
    questType type;
    int experience;
    int questCount;
    std::string questDescription;
    std::string questName;
    std::string enemyToKillName;
    std::string questMap;
public:
    friend std::istream &operator>>(std::istream &in, Quest &quest);

};


#endif //WIZARDTOWERGAME_QUEST_H
