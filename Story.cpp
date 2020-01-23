//
// Created by klonek on 23.01.20.
//

#include "Story.h"

Story::Story() {
    auto *map = new Maps("first");
    this->maps.push_back(map);
    this->currentMap = this->maps[0];
    this->player = new Player(sf::Vector2f(64.0f, 96.0f), "../assets/textures/character.png",
                              sf::IntRect(32, 64, 32, 32));
}

void Story::loadCurrentMap(std::vector<RendererObject *> &rendererObject, std::vector<MovableObjects *> &movableObjects,
                           std::vector<CollisionObject *> &collisionObject,
                           std::vector<FightingObject *> &fightingObjects) {

    rendererObject.erase(rendererObject.begin(), rendererObject.end());
    rendererObject.push_back(this->currentMap->getTileMap());
    rendererObject.push_back(player);
    rendererObject.insert(rendererObject.end(), this->currentMap->getEnemies().begin(),
                          this->currentMap->getEnemies().end());

    collisionObject.erase(collisionObject.begin(), collisionObject.end());
    collisionObject.push_back(player);
    collisionObject.push_back(this->currentMap->getTileMap());
    collisionObject.insert(collisionObject.end(), this->currentMap->getEnemies().begin(),
                           this->currentMap->getEnemies().end());

    movableObjects.erase(movableObjects.begin(), movableObjects.end());
    movableObjects.push_back(player);
    movableObjects.insert(movableObjects.end(), this->currentMap->getEnemies().begin(),
                          this->currentMap->getEnemies().end());


    fightingObjects.erase(fightingObjects.begin(), fightingObjects.end());
    fightingObjects.push_back(player);
    fightingObjects.insert(fightingObjects.end(), this->currentMap->getEnemies().begin(),
                           this->currentMap->getEnemies().end());

}

Player *Story::getPlayer() const {
    return player;
}

void Story::Update(std::vector<RendererObject *> &rendererObject, std::vector<MovableObjects *> &movableObjects,
                   std::vector<CollisionObject *> &collisionObject, std::vector<FightingObject *> &fightingObjects) {
    this->kill(fightingObjects);
    this->levelUp();
    this->changeMap();
    this->loadCurrentMap(rendererObject, movableObjects, collisionObject, fightingObjects);
}

void Story::kill(std::vector<FightingObject *> &fightingObjects) {
    for (auto &item : fightingObjects) {
        if (item->getCurrentLife() <= 0) {
            this->currentMap->getEnemies().erase(
                    std::remove(this->currentMap->getEnemies().begin(), this->currentMap->getEnemies().end(), item),
                    this->currentMap->getEnemies().end());
            this->player->increaseExperience(item->getExperience());

        }
    }
}

void Story::levelUp() {
    if (this->player->getExperience() >= this->player->getLevel() * 100) {
        this->player->setExpirience(this->player->getExperience() - (this->player->getLevel() * 100));
        this->player->LevelUp();

    }
}

void Story::changeMap() {
    for (const auto &door : this->currentMap->getDoors()) {
        std::cout << "contains: " << door->getDoor().contains(
                sf::Vector2f(this->player->getPosition().x + 16, this->player->getPosition().y + 16)) << " player pos "
                  << this->player->getPosition().x + 16 << " " << this->player->getPosition().y + 16
                  << " door pos " << door->getDoor().left << " " << door->getDoor().top << " " << door->getDoor().width
                  << " " << door->getDoor().height << std::endl;
        if (door->getDoor().contains(
                sf::Vector2f(this->player->getPosition().x + 16, this->player->getPosition().y + 16))) {
            auto it = std::find_if(this->maps.begin(), this->maps.end(), [door](const Maps *map) {
                return map->getMapName() == door->getDoorTo();
            });
            this->currentMap = *it;
            player->setPosition(door->getPositionBehindDoor());
        }
    }
}
