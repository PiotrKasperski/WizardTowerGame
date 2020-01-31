//
// Created by igor on 21.01.2020.
//


#ifndef WIZARDTOWERGAME_EQUIPMENT_H
#define WIZARDTOWERGAME_EQUIPMENT_H

#include "../RendererObject.h"
class Equipment: public RendererObject {
public:
    std::string name;
    bool isEquiped;
    int defense; // ile dmg jest redukowane (bron rowniez sluzy do obrony wiec wspolne)
    virtual void use(std::vector<Equipment *> eqVector);
    virtual void use(std::vector<Equipment *>  & eqPlayer, std::vector<Equipment *> & eqLoot);

    Equipment();
    ~Equipment();
};


#endif //WIZARDTOWERGAME_EQUIPMENT_H
