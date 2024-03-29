//
// Created by klonek on 15.01.20.
//

#ifndef WIZARDTOWERGAME_COLLISIONOBJECT_H
#define WIZARDTOWERGAME_COLLISIONOBJECT_H


#include <SFML/Graphics/Rect.hpp>
#include <vector>
#include "RendererObject.h"

class CollisionObject : public RendererObject {
public:
    virtual std::vector<sf::FloatRect *> *getBoundingBoxes();

    virtual bool isCollision(std::vector<CollisionObject *>);

    bool operator==(const CollisionObject &rhs) const;

    bool operator!=(const CollisionObject &rhs) const;

    CollisionObject();

    virtual ~CollisionObject();

private:
    bool isSelf(CollisionObject *);

public:
    void setPosition(const sf::Vector2f &position) override;

protected:
    std::vector<sf::FloatRect *> *boundingBoxes;

};


#endif //WIZARDTOWERGAME_COLLISIONOBJECT_H
