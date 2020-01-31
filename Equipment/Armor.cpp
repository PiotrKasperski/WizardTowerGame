//
// Created by klonek on 29.01.20.
//

#include "Armor.h"

Armor::Armor(std::string name, bool isEquiped, int DR, int defense) {
    this->isEquiped = isEquiped;
    this->name = name;
    this->damageReduction = DR;
    this->defense = defense;
}

void Armor::use(std::vector<Equipment *> eqVector) {
    // player handling
    if (this->isEquiped) {
        this->isEquiped = false;
    } else {
        for (auto &eq : eqVector) {
            if (eq->isEquiped && dynamic_cast<Armor *>(eq) != nullptr) eq->isEquiped = false;
            this->isEquiped = true;
        }
    }
    // loot handling


}

Armor::~Armor() {}