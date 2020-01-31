//
// Created by klonek on 29.01.20.
//

#ifndef WIZARDTOWERGAME_FIGHTMENAGER_H
#define WIZARDTOWERGAME_FIGHTMENAGER_H


#include "Equipment/Projectile.h"

class FightMenager {
    static std::vector<Projectile *> projectileVector;
    std::vector<FightingObject *> *fightingObjectVector;
public:
    FightMenager(std::vector<FightingObject *> *fightingObjectVector);

    void update(std::vector<CollisionObject *> colisionObjectVector);

    void moveProjectiles(std::vector<CollisionObject *> &colisionObjectVector);

    void checkHit(std::vector<CollisionObject *> &colisionObjectVector, Projectile &projectile);

    void manageHit(Projectile &projectile);

    void addProjectile(Projectile projectile);

    void draw(sf::RenderWindow *window);

    FightMenager();
};


#endif //WIZARDTOWERGAME_FIGHTMENAGER_H
