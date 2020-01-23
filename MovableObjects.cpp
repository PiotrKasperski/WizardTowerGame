//
// Created by klonek on 09.01.20.
//

#include "MovableObjects.h"

void MovableObjects::move(std::vector<CollisionObject *>) {
    this->position.x += 1;
    this->position.y += 1;
}

void MovableObjects::setPosition(const sf::Vector2f &position) {
    (*CollisionObject::boundingBoxes)[0]->top = position.y;
    (*CollisionObject::boundingBoxes)[0]->left = position.x;
    CollisionObject::setPosition(position);
}