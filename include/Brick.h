#ifndef BRICK_H
#define BRICK_H
#include<iostream>
#include<SFML/Graphics.hpp>

class Brick{
public:
    Brick(float x, float y);
    void draw(sf::RenderWindow& window);
    float GetWidth();
    float GetHeight();
    sf::FloatRect GetBody();
    void Destroy();

private:
    float brickWidth = 50.f;
    float brickHeight = 30.f;
    sf::RectangleShape brick;
};

#endif