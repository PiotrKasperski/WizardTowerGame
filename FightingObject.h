//
// Created by klonek on 21.01.20.
//

#ifndef WIZARDTOWERGAME_FIGHTINGOBJECT_H
#define WIZARDTOWERGAME_FIGHTINGOBJECT_H


#include <SFML/Graphics/Rect.hpp>
#include "Staticstics.h"
#include "MovableObjects.h"

class FightingObject : public Staticstics, public MovableObjects {
private:
    sf::FloatRect dmgBox, defenseBox;
public:
    virtual void TakeDamage(int gainedDmg, FightingObject &);

    virtual void MakeDamage(std::vector<FightingObject *> fightingObjects);

    virtual void Fight(std::vector<FightingObject *>);

    const sf::FloatRect &getDmgBox() const;

    void setDmgBox(const sf::FloatRect &dmgBox);

    void setDmgBoxPosition(const sf::Vector2f);

    const sf::FloatRect &getDefenseBox() const;

    void setDefenseBox(const sf::FloatRect &defenseBox);

    void Update(sf::RenderWindow &window) override;

    bool operator==(const FightingObject &rhs) const;

    bool operator!=(const FightingObject &rhs) const;

    bool operator!=(const CollisionObject &rhs) const;
};


#endif //WIZARDTOWERGAME_FIGHTINGOBJECT_H
