#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>
#include<SFML/Graphics.hpp>

class Player{
public:
    Player();
    void draw(sf::RenderWindow& window);
    void movement(sf::RenderWindow& window);
    float getMiddle();
    float getWidth();

private:
    float playerWidth = 120;
    float playerHeight = 10;
    sf::RectangleShape player;
};

#endif