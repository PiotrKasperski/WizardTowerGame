//
// Created by klonek on 29.01.20.
//

#include "FightMenager.h"

std::vector<Projectile *> FightMenager::projectileVector;

FightMenager::FightMenager(std::vector<FightingObject *> *fightingObjectVector) : fightingObjectVector(
        fightingObjectVector) {}

void FightMenager::update(std::vector<CollisionObject *> colisionObjectVector) {
    this->moveProjectiles(colisionObjectVector);
}

void FightMenager::moveProjectiles(std::vector<CollisionObject *> &colisionObjectVector) {
    for (auto projectile : FightMenager::projectileVector) {
        projectile->move(colisionObjectVector);
        checkHit(colisionObjectVector, *projectile);
    }
}

void FightMenager::checkHit(std::vector<CollisionObject *> &colisionObjectVector, Projectile &projectile) {
    if (projectile.isCollision(colisionObjectVector)) {
        this->manageHit(projectile);
    }
}

void FightMenager::manageHit(Projectile &projectile) {
    for (auto &fightingObject : *this->fightingObjectVector) {
        if (fightingObject->getDefenseBox().intersects(projectile.getDmgBox())) {
            fightingObject->TakeDamage(projectile.damage, *fightingObject);
        }
        FightMenager::projectileVector.erase(
                std::remove(FightMenager::projectileVector.begin(), FightMenager::projectileVector.end(), &projectile),
                FightMenager::projectileVector.end());
    }
}

void FightMenager::addProjectile(Projectile projectile) {
    Projectile *tmp = new Projectile(projectile);
    FightMenager::projectileVector.push_back(tmp);
}

FightMenager::FightMenager() {}

void FightMenager::draw(sf::RenderWindow *window) {
    for (const auto item : projectileVector) {
        item->Draw(*window);
    }
}
