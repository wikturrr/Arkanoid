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

sf::Rect<float> Brick::getLowerVerticalBounds(){
    return sf::FloatRect({brick.getPosition().x,brick.getPosition().y + brickHeight-2.5f},{brickWidth, 5.0f});

}

sf::Rect<float> Brick::getUpperVerticalBounds(){
    return sf::FloatRect({brick.getPosition().x,brick.getPosition().y- 2.5f},{brickWidth, 5.0f});
}

sf::Rect<float> Brick::getRightHorizontalBounds(){
    return sf::FloatRect({brick.getPosition().x + brickWidth - 2.5f, brick.getPosition().y + 2.0f}, {5.f, brickHeight - 8.0f});
}

sf::Rect<float> Brick::getLeftHorizontalBounds(){
    return sf::FloatRect({brick.getPosition().x - 2.5f, brick.getPosition().y + 2.0f}, {5.f, brickHeight - 8.0f});
}