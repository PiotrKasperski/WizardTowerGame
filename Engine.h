//
// Created by klonek on 09.01.20.
//

#ifndef WIZARDTOWERGAME_ENGINE_H
#define WIZARDTOWERGAME_ENGINE_H


#include <SFML/Graphics/RenderWindow.hpp>
#include "RendererObject.h"
#include "Player.h"


class Engine {
public:
    Engine();

    Engine(sf::RenderWindow &window);

private:
    std::vector<RendererObject*> rendererObject;
    std::vector<MovableObjects*> movableObjects;

    sf::RenderWindow *window;

    void runEngine();

    void gameLoop();

    void eventHandler();

    void update();

    void draw();

    Player *player;

};


#endif //WIZARDTOWERGAME_ENGINE_H
