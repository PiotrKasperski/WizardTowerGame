//
// Created by klonek on 09.01.20.
//

#include <SFML/Window/Event.hpp>
#include "Engine.h"

Engine::Engine() {}

Engine::Engine(sf::RenderWindow &window){
    this->window = &window;
    player = new Player(sf::Vector2i(0,0), "../assets/textures/character.png", sf::IntRect(32, 64, 32,32));
    this->rendererObject.push_back(player);
    this->movableObjects.push_back(player);
    this->runEngine();
}

void Engine::runEngine() {
    gameLoop();
}

void Engine::gameLoop() {
    sf::Clock clock;
    sf::Time timeFromUpdate;
    const sf::Time timeStep = sf::seconds(1.f/60.f);
    while (this->window->isOpen()) {

        sf::Time time = clock.restart();
        timeFromUpdate += time;
        while(timeFromUpdate > timeStep){

            timeFromUpdate -= timeStep;

            Engine::eventHandler();

            Engine::update();

        }

        Engine::draw();


    }
}

void Engine::eventHandler() {
    sf::Event event;
    while (this->window->pollEvent(event))
    {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
            window->close();
    }

}

void Engine::update() {
    for(int i =0; i < this->movableObjects.size(); i++){
        movableObjects[i]->move();
    }
    for(int i =0; i < this->rendererObject.size(); i++){
        this->rendererObject[i]->Update(*window);
    }
}

void Engine::draw() {
    window->clear();
    for(int i =0; i < this->rendererObject.size(); i++){
        this->rendererObject[i]->Draw(*window);
    }
    window->display();
}
