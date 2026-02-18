#include "Brick.h"

Brick::Brick(float x, float y){
    brick.setSize({brickWidth, brickHeight});
    brick.setFillColor({28, 92, 57});
    brick.setPosition({x,y});
    brick.setOutlineThickness({1.5f});
    brick.setOutlineColor(sf::Color::Black);
}

void Brick::draw(sf::RenderWindow& window){
    window.draw(brick);
}

float Brick::GetWidth(){
    return brickWidth;
}
float Brick::GetHeight(){
    return brickHeight;
}

sf::FloatRect Brick::GetBody(){
    return brick.getGlobalBounds();
}

void Brick::Destroy(){
    brick.setPosition({1000.f, 1000.f});
}
