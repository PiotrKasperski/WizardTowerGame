//
// Created by igor on 20.01.2020.
//

#ifndef WIZARDTOWERGAME_STATS_H
#define WIZARDTOWERGAME_STATS_H

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Staticstics{
private:

public:
    Staticstics();
    int level;
    int expirience;
    int maxLife;
    int currentLife;
    int strenght;
    float speed;
    int defence;
    int freePoints;
    int stamina;
    int getExperience();
    int getMaxLife();
    int getLevel();
    void IncreaseStatistics();
    void increaseExperience(int gainedExpirence);
    void LevelUp();

};
#endif //WIZARDTOWERGAME_STATS_H
