//
// Created by igor on 20.01.2020.
//

#ifndef WIZARDTOWERGAME_STATICSTICS_H
#define WIZARDTOWERGAME_STATICSTICS_H

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Staticstics{
private:
    int level;
    int expirience;
    int maxLife;
    int currentLife;
    int strenght;
    float speed;
    int defence;
    int freePoints;
    int stamina;
public:
    void setLevel(int level);

    int getExpirience() const;

    void setExpirience(int expirience);

    void setMaxLife(int maxLife);

    int getCurrentLife() const;

    void setCurrentLife(int currentLife);

    int getStrenght() const;

    void setStrenght(int strenght);

    float getSpeed() const;

    void setSpeed(float speed);

    int getDefence() const;

    void setDefence(int defence);

    int getFreePoints() const;

    void setFreePoints(int freePoints);

    int getStamina() const;

    void setStamina(int stamina);

public:
    Staticstics();

    int getExperience();
    int getMaxLife();
    int getLevel();
    void IncreaseStatistics();
    void increaseExperience(int gainedExpirence);
    void LevelUp();

};

#endif //WIZARDTOWERGAME_STATICSTICS_H
