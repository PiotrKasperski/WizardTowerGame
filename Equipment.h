//
// Created by igor on 21.01.2020.
//


#ifndef WIZARDTOWERGAME_EQUIPMENT_H
#define WIZARDTOWERGAME_EQUIPMENT_H

#include "RendererObject.h"
class Equipment: public RendererObject {
public:
    std::string name;
    bool isEquiped;
    int defense; // ile dmg jest redukowane (bron rowniez sluzy do obrony wiec wspolne)
    virtual void use(std::vector<Equipment *> eqVector);

    Equipment();
    ~Equipment();
};
class Weapon: public Equipment {
public:
    int AttackPower;
    void use(std::vector<Equipment *> eqVector); //equip and deequip
    Weapon();
    Weapon(std::string name, bool isEquiped, int AP, int defense);
    ~Weapon();
};
class Armor: public Equipment {
public:
    int damageReduction; // dodatkowy atrybut zmniejszajacy obrazenia;
    void use(std::vector<Equipment *> eqVector);
    Armor();
    Armor(std::string name, bool isEquiped, int DR, int defense);
    ~Armor();
};


#endif //WIZARDTOWERGAME_EQUIPMENT_H
