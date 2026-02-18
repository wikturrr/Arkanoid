#ifndef GAME_H
#define GAME_H
#include<iostream>
#include<SFML/Graphics.hpp>
#include "Player.h"
#include "Ball.h"
#include "Brick.h"

class Game{
public:
    Game();
    void run();
   

private:
    unsigned int windowWidth = 600;
    unsigned int windowHeight = 800;
    float playgroundWidth = 600;
    float PlaygroundHeight = 700;
    sf::RenderWindow window;
    sf::RectangleShape playground;
};

#endif