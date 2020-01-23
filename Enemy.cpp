//
// Created by klonek on 21.01.20.
//

#include <iostream>
#include "Enemy.h"


void Enemy::move(std::vector<CollisionObject *> colObjVector) {
    std::srand(std::time(NULL));
    if (MovableObjects::moveVector.x == 0 && MovableObjects::moveVector.y == 0 && !isAttack) {
        MovableObjects::moveVector.x = ((std::rand() % 3) - 1);
        MovableObjects::moveVector.y = ((std::rand() % 3) - 1);
    }
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

    if (isAttack) {
        Enemy::moveVector = sf::Vector2f(fightedObject->getPosition().x - Enemy::position.x >= 0 ? 1 : -1,
                                         fightedObject->getPosition().y - Enemy::position.y >= 0 ? 1 : -1);
    }
    Enemy::position = sf::Vector2f((*CollisionObject::boundingBoxes)[0]->left,
                                   (*CollisionObject::boundingBoxes)[0]->top);


}


void Enemy::Update(sf::RenderWindow &window) {
    FightingObject::Update(window);
    Enemy::sprite.setPosition(Enemy::position);
    Enemy::setDefenseBox(this->sprite.getGlobalBounds());
    std::cout << Enemy::getCurrentLife() << std::endl;
}

Enemy::Enemy(const sf::Vector2f &position, const std::string &textureFilename, sf::IntRect textureRect) {
    this->Create(position, textureFilename, textureRect);

}


void Enemy::MakeDamage(std::vector<FightingObject *> fightingObjects) {
    FightingObject::MakeDamage(fightingObjects);
}

void Enemy::Fight(std::vector<FightingObject *> vector) {

    //if (fightedObject && (Enemy::getDmgBox().intersects(fightedObject->getSprite().getGlobalBounds() ) || Enemy::getDmgBox().contains(fightedObject->getSprite().getGlobalBounds().left,fightedObject->getSprite().getGlobalBounds().top)))

    if (isAttack) Enemy::MakeDamage(vector);


}

void Enemy::TakeDamage(int gainedDmg, FightingObject &object) {
    FightingObject::TakeDamage(gainedDmg, object);
    fightedObject = &object;
    isAttack = true;
}
std::istream & operator >> (std::istream &in,  Enemy &enemy)
{
    std::srand(std::time(NULL));
    in >> enemy.enemyName;
    in >> enemy.level;
    in >> enemy.experience;
    in >> enemy.maxLife;
    enemy.currentLife = enemy.maxLife;
    int random;
    in>>random;
    in >> enemy.strenght;
    enemy.strenght += ((std::rand() % (random*2)+1) - random);
    in>>enemy.speed;
    in>>enemy.defence;
    enemy.defence += ((std::rand() % (random*2)+1) - random);
    in>>enemy.stamina;
    in>>enemy.textureName;
    enemy.Create(sf::Vector2f(0.0f, 0.0f), enemy.textureName, sf::IntRect(32, 64, 32, 32));

    return in;
}

std::ostream &operator<<(std::ostream &os, const Enemy &enemy) {
    os  << " enemyName: " << enemy.enemyName;
    return os;
}

void Enemy::Create(const sf::Vector2f &position, const std::string &textureFilename, sf::IntRect textureRect) {
    isAttack = false;
    Enemy::position = position;
    Enemy::textureName =textureFilename;
    Enemy::texture.loadFromFile("../assets/textures/"+textureFilename+".png");
    Enemy::sprite.setTexture(Enemy::texture);
    Enemy::sprite.setTextureRect(textureRect);
    Enemy::sprite.setPosition(Enemy::position);
    MovableObjects::moveVector = sf::Vector2f(0.0f, 0.0f);
    CollisionObject::boundingBoxes = new std::vector<sf::FloatRect *>();
    CollisionObject::boundingBoxes->push_back(new sf::FloatRect(this->sprite.getGlobalBounds()));
    Enemy::setDefenseBox(*new sf::FloatRect(this->sprite.getGlobalBounds()));
    Enemy::setDmgBox(sf::FloatRect(
            sf::Vector2f(this->sprite.getGlobalBounds().left - 32, this->sprite.getGlobalBounds().top - 32),
            sf::Vector2f(96.0f, 96.0f)));
}

Enemy::Enemy() {}






/*Enemy::Enemy(const sf::Vector2f &position, const std::string &textureFilename, sf::IntRect textureRect) {
    Enemy::position =position;
    Enemy::texture

}*/
