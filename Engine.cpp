//
// Created by klonek on 09.01.20.
//

#include <SFML/Window/Event.hpp>
#include <iostream>
#include "Engine.h"

Engine::Engine() {}

Engine::Engine(sf::RenderWindow &window) {


    this->window = &window;

    this->map = new TileMap("../assets/textures/tileset.png", sf::Vector2u(32, 32), level, 16, 8);

    this->player = new Player(sf::Vector2f(68.0f, 70.0f), "../assets/textures/character.png",
                              sf::IntRect(32, 64, 32, 32));

    this->rendererObject.push_back(player);

    this->movableObjects.push_back(player);

    this->collisionObject.push_back(this->map);
    this->collisionObject.push_back(this->player);


    this->runEngine();
}

void Engine::runEngine() {
    gameLoop();
}

void Engine::gameLoop() {

    sf::Clock clock;
    sf::Time timeFromUpdate;
    const sf::Time timeStep = sf::seconds(1.f / 60.f);
    while (this->window->isOpen()) {

        sf::Time time = clock.restart();
        timeFromUpdate += time;

        while (timeFromUpdate > timeStep) {

            timeFromUpdate -= timeStep;

            Engine::eventHandler();

            Engine::update();

        }

        Engine::draw();

    }
}

void Engine::eventHandler() {
    sf::Event event;
    while (this->window->pollEvent(event)) {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
            window->close();
    }

}

void Engine::update() {
    for (int i = 0; i < this->movableObjects.size(); i++) {
        movableObjects[i]->move(collisionObject);
    }
    for (int i = 0; i < this->rendererObject.size(); i++) {
        this->rendererObject[i]->Update(*window);
    }
}

void Engine::draw() {
    window->clear();

    this->window->draw(this->map[0]);

    for (int i = 0; i < this->rendererObject.size(); i++) {
        this->rendererObject[i]->Draw(*window);
    }

    window->display();
}

