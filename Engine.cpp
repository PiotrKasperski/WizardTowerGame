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

    story->loadCurrentMap(this->rendererObject, this->movableObjects, this->collisionObject, this->fightingObjects);

    this->camera = sf::View(story->getPlayer()->getPosition(),
                            sf::Vector2f(this->window->getSize().x, this->window->getSize().y));
    this->window->setView(this->camera);
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
    this->camera.setCenter(this->story->getPlayer()->getPosition());
    this->window->setView(this->camera);
}

void Engine::draw() {
    window->clear();


    for (const auto &object : rendererObject) {
        object->Draw(*this->window);
    }

    window->display();
}

void Engine::cleanVectors(RendererObject *object) {
    rendererObject.erase(std::find(rendererObject.begin(), rendererObject.end(), object));
    fightingObjects.erase(std::find(fightingObjects.begin(), fightingObjects.end(), object));
    movableObjects.erase(std::find(movableObjects.begin(), movableObjects.end(), object));
    collisionObject.erase(std::find(collisionObject.begin(), collisionObject.end(), object));
    delete (object);
}

void Engine::gameOver() {
    std::cout << "GAMEOVER";
    // rendererObject.erase(std::find(rendererObject.begin(), rendererObject.end(), player));
}

