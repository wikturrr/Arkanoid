#include "Player.h"

Player::Player(){
    player.setSize({playerWidth, playerHeight});
    player.setPosition({250.f, 700.f});
    player.setFillColor({167, 167, 167});
    player.setOutlineThickness({3.f});
    player.setOutlineColor(sf::Color::Black);
}

void Player::draw(sf::RenderWindow& window){
    window.draw(player);  
}

void Player::movement(sf::RenderWindow& window){
    if((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && player.getPosition().x != 0)){
        player.move({-10.f,0});
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && player.getPosition().x != 600 - playerWidth){
        player.move({10.f,0});
    }
}

float Player::getMiddle(){
    return (player.getPosition().x + (playerWidth/2));
}

float Player::getWidth(){
    return playerWidth;
}