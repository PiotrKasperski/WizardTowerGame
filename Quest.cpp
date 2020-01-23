//
// Created by klonek on 23.01.20.
//

#include "Quest.h"

std::istream &operator>>(std::istream &in, Quest &quest) {
    std::string inType;
    in>>inType;
    if(inType == "KILL") quest.type = Quest::KILL;
    else quest.type = Quest::FIND;
    in>>quest.experience;
    in>>quest.questCount;
    in>>quest.questName;
    in>>quest.enemyToKillName;
    in>>quest.questMap;
    in.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
    std::getline(in, quest.questDescription);
    return in;
}
