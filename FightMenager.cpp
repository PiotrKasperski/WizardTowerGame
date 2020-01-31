//
// Created by klonek on 29.01.20.
//

#include "FightMenager.h"
#include <iostream>

std::vector<Projectile *> FightMenager::projectileVector;

FightMenager::FightMenager(std::vector<FightingObject *> *fightingObjectVector) : fightingObjectVector(
        fightingObjectVector) {}

void FightMenager::update(std::vector<CollisionObject *> colisionObjectVector) {
    this->moveProjectiles(colisionObjectVector);
    this->clear();
}

void FightMenager::moveProjectiles(std::vector<CollisionObject *> &colisionObjectVector) {
    for (auto projectile : FightMenager::projectileVector) {
        checkHit(colisionObjectVector, *projectile);
        projectile->move(colisionObjectVector);

    }
}

void FightMenager::checkHit(std::vector<CollisionObject *> &colisionObjectVector, Projectile &projectile) {
    if (projectile.isCollision(colisionObjectVector)) {
        this->manageHit(projectile);
    }
}

void FightMenager::manageHit(Projectile &projectile) {
    for (auto &fightingObject : *this->fightingObjectVector) {
        if (fightingObject->getDefenseBox().intersects(projectile.getDmgBox()) &&
            projectile.attacker->getName().compare(fightingObject->getName())) {
            fightingObject->TakeDamage(projectile.damage, *fightingObject);

        }
    }
}

void FightMenager::addProjectile(Projectile projectile) {
    Projectile *tmp = new Projectile(projectile.getPosition(), projectile.rotation, projectile.size, projectile.name,
                                     projectile.speed, projectile.maxDistance, projectile.damage, *projectile.attacker);
    FightMenager::projectileVector.push_back(tmp);
}

FightMenager::FightMenager() {}

void FightMenager::draw(sf::RenderWindow *window) {
    this->clear();
    for (const auto item : projectileVector) {
        item->Draw(*window);
    }
}

std::vector<Projectile *> &FightMenager::getProjectileVector() {
    return projectileVector;
}

void FightMenager::clear() {
    for (auto &projectile : projectileVector) {
        if (projectile->hited) {
            FightMenager::projectileVector.erase(
                    std::remove(FightMenager::projectileVector.begin(), FightMenager::projectileVector.end(),
                                projectile),
                    FightMenager::projectileVector.end());
        }
    }
}

