//
// Created by klonek on 09.01.20.
//

#ifndef WIZARDTOWERGAME_MOVABLEOBJECTS_H
#define WIZARDTOWERGAME_MOVABLEOBJECTS_H


#include "RendererObject.h"
#include "CollisionObject.h"

class MovableObjects : public RendererObject {
public:
    virtual void move(std::vector<CollisionObject *>);

protected:
    sf::Vector2f moveVector;
};


#endif //WIZARDTOWERGAME_MOVABLEOBJECTS_H
