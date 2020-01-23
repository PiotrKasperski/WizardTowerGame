//
// Created by klonek on 09.01.20.
//

#include <SFML/Window/Event.hpp>
#include <iostream>
#include "Engine.h"
#include "Enemy.h"

Engine::Engine() {}

Engine::Engine(sf::RenderWindow &window) {


    this->window = &window;

    this->story = new Story;

    this->interface = new Interface(this->story->getPlayer());

    story->loadCurrentMap(this->rendererObject, this->movableObjects, this->collisionObject, this->fightingObjects);

    this->camera = new Camera(*this->window, story->getPlayer()->getPosition());

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
    for (auto &movableObject : movableObjects) {
        movableObject->move(collisionObject);
    }
    for (const auto &object : rendererObject) {
        object->Update(*this->window);
    }
    for (auto &fightingObject : fightingObjects) {
        fightingObject->Fight(this->fightingObjects);
    }
    this->story->Update(this->rendererObject, this->movableObjects, this->collisionObject, this->fightingObjects);
    this->camera->Update(this->story->getPlayer()->getPosition());
    //updating GUI data
    this->interface->update(*window);
}

void Engine::draw() {
    window->clear();


    for (const auto &object : rendererObject) {
        object->Draw(*this->window);
    }
    // rendering gui data
    this->interface->render(*window);

    window->display();
}



