//
// Created by klonek on 29.01.20.
//

#ifndef WIZARDTOWERGAME_WEAPON_H
#define WIZARDTOWERGAME_WEAPON_H

#include "Equipment.h"
#include "Projectile.h"

class Weapon : public Equipment {
public:
    int AttackPower;
    Projectile projectile;

    void use(std::vector<Equipment *> eqVector); //equip and deequip
    Weapon();

    Weapon(std::string name, bool isEquiped, int AP, int defense);

    ~Weapon();
};


#endif //WIZARDTOWERGAME_WEAPON_H
