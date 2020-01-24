//
// Created by klonek on 23.01.20.
//

#ifndef WIZARDTOWERGAME_STORY_H
#define WIZARDTOWERGAME_STORY_H


#include "Maps.h"
#include "Quest.h"

class Story {
private:
    std::vector<Maps *> maps;
    std::vector<Quest *> quests;
public:
    friend std::istream &operator>>(std::istream &in, Story &story);

};


#endif //WIZARDTOWERGAME_STORY_H
