//
// Created by klonek on 09.01.20.
//

#ifndef WIZARDTOWERGAME_ENGINE_H
#define WIZARDTOWERGAME_ENGINE_H


#include <SFML/Graphics/RenderWindow.hpp>
#include "RendererObject.h"
#include "Player.h"
#include "TileMap.h"
#include "Enemy.h"
#include "Story.h"
#include "Camera.h"
#include "Interface/Hud/Hud.h"
#include "Interface/InventoryGui/InventoryGui.h"
#include "Interface/StatsGui/StatsGui.h"
#include "Interface/LootGui/LootGui.h"

class Engine {
public:
    Engine();

    Engine(sf::RenderWindow &window);

private:
    std::vector<RendererObject *> rendererObject;
    std::vector<MovableObjects *> movableObjects;
    std::vector<CollisionObject *> collisionObject;
    std::vector<FightingObject *> fightingObjects;
    std::vector<Projectile *> projectileObjects;
    sf::RenderWindow *window;

    void runEngine();

    void gameLoop();

    void eventHandler();

    void update();

    void draw();

    Projectile *projectile1;
    Hud *hud;
    InventoryGui *invGui;
    StatsGui *statsGui;
    LootGui *lootGui;
    Story *story;

    Camera *camera;



};


#endif //WIZARDTOWERGAME_ENGINE_H
