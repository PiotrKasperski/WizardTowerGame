//
// Created by klonek on 09.01.20.
//

#ifndef WIZARDTOWERGAME_MOVABLEOBJECTS_H
#define WIZARDTOWERGAME_MOVABLEOBJECTS_H


#include "RendererObject.h"
#include "CollisionObject.h"

class MovableObjects : public CollisionObject {
public:
    virtual void move(std::vector<CollisionObject *>);

    void setPosition(const sf::Vector2f &position) override;

    bool operator==(const MovableObjects &rhs) const;

    bool operator!=(const MovableObjects &rhs) const;

protected:
    sf::Vector2f moveVector;
};


#endif //WIZARDTOWERGAME_MOVABLEOBJECTS_H
