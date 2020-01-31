//
// Created by igor on 20.01.2020.
//

#ifndef WIZARDTOWERGAME_STATICSTICS_H
#define WIZARDTOWERGAME_STATICSTICS_H

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Staticstics{

protected:
    int level;
    int experience;
    int maxLife;
    int currentLife;
    int strenght;
    float speed;
    int defence;
    int freePoints;
    int stamina;
    std::string name;
public:
    const std::string &getName() const;

    void setName(const std::string &name);

public:
    void setLevel(int level);

    int getExpirience() const;

    void setExpirience(int experience);

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

    bool operator==(const Staticstics &rhs) const;

    bool operator!=(const Staticstics &rhs) const;

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
