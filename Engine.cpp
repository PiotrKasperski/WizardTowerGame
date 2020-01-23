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
    this->enemy =new Enemy;
    if(!files.loadEnemy("pies", *this->enemy, *this->map)){
        throw std::runtime_error("Unable to load enemy file");
    }
    auto *story = new Story;
    if(!files.loadStory("story", *story)){
        throw std::runtime_error("Unable to load story file");
    }

    this->player = new Player(sf::Vector2f(64.0f, 96.0f), "../assets/textures/character.png",
                              sf::IntRect(32, 64, 32, 32));
    //this->enemy = new Enemy(sf::Vector2f(64.0f, 2 * 96.0f), "character",
      //                      sf::IntRect(32, 64, 32, 32));

    this->rendererObject.push_back(map);
    this->rendererObject.push_back(player);
    this->rendererObject.push_back(enemy);

    this->movableObjects.push_back(player);
    this->movableObjects.push_back(enemy);

    this->collisionObject.push_back(this->map);
    this->collisionObject.push_back(this->player);
    this->collisionObject.push_back(this->enemy);

    this->fightingObjects.push_back(player);
    this->fightingObjects.push_back(enemy);

    this->camera = sf::View(this->player->getPosition(),
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
        if (fightingObject->getCurrentLife() <= 0) {
            if (this->player->getCurrentLife() <= 0) {
                gameOver();
            } else
                this->cleanVectors(fightingObject);
        }
    }
    this->camera.setCenter(this->player->getPosition());
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

