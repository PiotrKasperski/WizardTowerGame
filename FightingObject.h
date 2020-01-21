//
// Created by klonek on 21.01.20.
//

#ifndef WIZARDTOWERGAME_FIGHTINGOBJECT_H
#define WIZARDTOWERGAME_FIGHTINGOBJECT_H


#include <SFML/Graphics/Rect.hpp>
#include "Staticstics.h"
#include "MovableObjects.h"

class FightingObject : public Staticstics {
private:
    sf::FloatRect dmgBox, defenseBox;
public:
    virtual void TakeDamage(int gainedDmg);

    virtual void MakeDamage(std::vector<FightingObject *> fightingObjects);

    const sf::FloatRect &getDmgBox() const;

    void setDmgBox(const sf::FloatRect &dmgBox);

    const sf::FloatRect &getDefenseBox() const;

    void setDefenseBox(const sf::FloatRect &defenseBox);

};


#endif //WIZARDTOWERGAME_FIGHTINGOBJECT_H
