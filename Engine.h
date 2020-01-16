//
// Created by klonek on 09.01.20.
//

#ifndef WIZARDTOWERGAME_ENGINE_H
#define WIZARDTOWERGAME_ENGINE_H


#include <SFML/Graphics/RenderWindow.hpp>
#include "RendererObject.h"
#include "Player.h"
#include "TileMap.h"
#include "Menu.h"

class Engine {
public:
    Engine();

    Engine(sf::RenderWindow &window);

private:
    std::vector<RendererObject *> rendererObject;
    std::vector<MovableObjects *> movableObjects;

    sf::RenderWindow *window;

    void runEngine();

    void gameLoop();

    void eventHandler();

    void update();

    void draw();

    Player *player;
    TileMap *map;

    int level[128] = {
            0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
            1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
            0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
            0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
            0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
            2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
            0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
    };;


};


#endif //WIZARDTOWERGAME_ENGINE_H
