//
// Created by klonek on 21.01.20.
//

#include <iostream>
#include "Enemy.h"


void Enemy::move(std::vector<CollisionObject *> colObjVector) {
    std::srand(std::time(NULL));
    if (MovableObjects::moveVector.x == 0 && MovableObjects::moveVector.y == 0) {
        MovableObjects::moveVector.x = ((std::rand() % 3) - 1);
        MovableObjects::moveVector.y = ((std::rand() % 3) - 1);
    }
    std::cout << MovableObjects::moveVector.x << " " << MovableObjects::moveVector.y << std::endl;
    (*CollisionObject::boundingBoxes)[0]->left += MovableObjects::moveVector.x;

    if (isCollision(colObjVector)) {
        (*CollisionObject::boundingBoxes)[0]->left -= MovableObjects::moveVector.x;
        MovableObjects::moveVector.x = MovableObjects::moveVector.y = 0.0f;
    }

    (*CollisionObject::boundingBoxes)[0]->top += MovableObjects::moveVector.y;
    if (isCollision(colObjVector)) {
        (*CollisionObject::boundingBoxes)[0]->top -= MovableObjects::moveVector.y;
        MovableObjects::moveVector.x = MovableObjects::moveVector.y = 0.0f;
    }
    Enemy::position = sf::Vector2f((*CollisionObject::boundingBoxes)[0]->left,
                                   (*CollisionObject::boundingBoxes)[0]->top);


}


void Enemy::Update(sf::RenderWindow &window) {
    Enemy::sprite.setPosition(Enemy::position);
}

Enemy::Enemy(const sf::Vector2f &position, const std::string &textureFilename, sf::IntRect textureRect) {
    Enemy::position = position;
    Enemy::texture.loadFromFile(textureFilename);
    Enemy::sprite.setTexture(Enemy::texture);
    Enemy::sprite.setTextureRect(textureRect);
    Enemy::sprite.setPosition(Enemy::position);
    MovableObjects::moveVector = sf::Vector2f(0.0f, 0.0f);
    CollisionObject::boundingBoxes = new std::vector<sf::FloatRect *>();
    CollisionObject::boundingBoxes->push_back(new sf::FloatRect(this->sprite.getGlobalBounds()));

}




/*Enemy::Enemy(const sf::Vector2f &position, const std::string &textureFilename, sf::IntRect textureRect) {
    Enemy::position =position;
    Enemy::texture

}*/
