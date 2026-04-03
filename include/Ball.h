#ifndef BALL_H
#define BALL_H
#include<SFML/Graphics.hpp>
#include<iostream>
#include "Player.h"
#include "Brick.h"

class Ball{
public:
    Ball();
    void draw(sf::RenderWindow &window);
    void launch(sf::RenderWindow& window);
    void movement(sf::RenderWindow& window, Player &player);
    void collisionWithBrick(Brick& brick);
    std::string GetScore();
    std::string GetLifes();
    int getLifes(){
        return numbersOfBalls;
    }
private:
    int score = 0;
    int numbersOfBalls = 3;
    bool canDestroy = true;
    bool isNew = true;
    float ballRadius = 10.f;
    sf::Vector2f ballMovement;
    sf::CircleShape ball;
};

#endif