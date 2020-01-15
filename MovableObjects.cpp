//
// Created by klonek on 09.01.20.
//

#include "MovableObjects.h"

void MovableObjects::move(std::vector<CollisionObject *>) {
    this->position.x += 1;
    this->position.y += 1;
}
