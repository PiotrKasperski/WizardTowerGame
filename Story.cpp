//
// Created by klonek on 23.01.20.
//

#include "Story.h"
std::istream & operator >> (std::istream &in,  Story &story)
{
    int i;
    in>>i;
    for (int j = 0; j < i; ++j) {
        Maps *map =new Maps;
        in >> *map;
        story.maps.push_back(map);
    }
    in>>i;
    for (int k = 0; k < i; ++k) {
        auto *quest =new Quest;
        in>>*quest;
        story.quests.push_back(quest);
    }

    return in;
}