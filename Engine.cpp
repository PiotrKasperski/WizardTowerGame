//
// Created by klonek on 09.01.20.
//

#include <SFML/Window/Event.hpp>
#include <iostream>
#include "Engine.h"
#include "Enemy.h"
#include "FileLoader.h"

Engine::Engine() {}

Engine::Engine(sf::RenderWindow &window) {
    FileLoader files;

    this->window = &window;
    this->map = new TileMap();

    if (!files.loadMap("first", *this->map)) {
        throw std::runtime_error("Unable to load map file");
    }
    this->enemy = new Enemy;
    if (!files.loadEnemy("pies", *this->enemy, *this->map)) {
        throw std::runtime_error("Unable to load enemy file");
    }
    auto *story = new Story;
    if (!files.loadStory("story", *story)) {
        throw std::runtime_error("Unable to load story file");
    }

    this->player = new Player(sf::Vector2f(64.0f, 96.0f), "../assets/textures/character.png",
                              sf::IntRect(32, 64, 32, 32));
    //this->enemy = new Enemy(sf::Vector2f(64.0f, 2 * 96.0f), "character",
    //                      sf::IntRect(32, 64, 32, 32));
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



