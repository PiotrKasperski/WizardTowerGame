//
// Created by klonek on 29.01.20.
//

#ifndef WIZARDTOWERGAME_ARMOR_H
#define WIZARDTOWERGAME_ARMOR_H


#include "Equipment.h"

class Armor : public Equipment {
public:
    int damageReduction; // dodatkowy atrybut zmniejszajacy obrazenia;
    void use(std::vector<Equipment *> eqVector);

    Armor();

    Armor(std::string name, bool isEquiped, int DR, int defense);

    ~Armor();
};


#endif //WIZARDTOWERGAME_ARMOR_H
