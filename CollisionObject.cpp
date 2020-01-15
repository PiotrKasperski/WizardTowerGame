//
// Created by klonek on 15.01.20.
//

#include "CollisionObject.h"


bool CollisionObject::isCollision(std::vector<CollisionObject *> colObj) {
    std::for_each(colObj.begin(), colObj.end(), [this](CollisionObject *object) {
        if (!this->isSelf(object)) {
            std::for_each(this->getBoundingBoxes()->begin(), this->getBoundingBoxes()->end(),
                          [object](sf::FloatRect *thisBoundingBox) {
                              std::for_each(object->getBoundingBoxes()->begin(), object->getBoundingBoxes()->end(),
                                            [thisBoundingBox](sf::FloatRect *objectBoundingBox) {
                                                return thisBoundingBox->intersects(*objectBoundingBox);
                                            });
                          });
        }
    });

    return false;
}

bool CollisionObject::isSelf(CollisionObject *object) {
    return object->getBoundingBoxes() == this->boundingBoxes;
}


CollisionObject::CollisionObject() {
    this->boundingBoxes = new std::vector<sf::FloatRect *>;
}

CollisionObject::~CollisionObject() {
    delete CollisionObject::boundingBoxes;
}


std::vector<sf::FloatRect *> *CollisionObject::getBoundingBoxes() {
    return this->boundingBoxes;
}
