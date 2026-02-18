#include "Ball.h"

Ball::Ball(){
    ball.setRadius(ballRadius);
    ball.setPosition({900.f, 900.f});
    ball.setFillColor(sf::Color::White);
    ballMovement = sf::Vector2f(-1.f,-8.f);
}

void Ball::draw(sf::RenderWindow &window){
    window.draw(ball);
}

void Ball::movement(sf::RenderWindow& window, Player &player){
    canDestroy = true;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)){
            isNew = false;
    }
    if(isNew == false){
        ball.move(ballMovement);
    }
    if(isNew == true){
        ball.setPosition({player.getMiddle()-8 ,670.f});
    }

    if(ball.getPosition().y < 100.f){
        ballMovement.y = -ballMovement.y;
    }
    if(ball.getPosition().x < 0 || ball.getPosition().x >600-20){
        ballMovement.x = -ballMovement.x;
    }

    if((ball.getPosition().y >= 700 - (int)ballRadius*2 && ball.getPosition().y <= 700) && ((ball.getPosition().x >= player.getMiddle() - player.getWidth()/2 - (int)ballRadius/2) && (ball.getPosition().x <= player.getMiddle() - (player.getWidth()/2)*0.8))){
        ballMovement.y = -ballMovement.y;
        ballMovement.x = -10.f;
        canDestroy = true;
    }else if((ball.getPosition().y >= 700 - (int)ballRadius*2 && ball.getPosition().y <= 700) && ((ball.getPosition().x >= player.getMiddle() - (player.getWidth()/2)*0.8) && (ball.getPosition().x <= player.getMiddle() - (player.getWidth()/2)*0.5))){
        ballMovement.y = -ballMovement.y;
        ballMovement.x = -7.f;
        canDestroy = true;
    }else if((ball.getPosition().y >= 700 - (int)ballRadius*2 && ball.getPosition().y <= 700) && ((ball.getPosition().x >= player.getMiddle() - (player.getWidth()/2)*0.5) && (ball.getPosition().x <= player.getMiddle()))){
        ballMovement.y = -ballMovement.y;
        ballMovement.x = -2.f;
        canDestroy = true;
    }else if((ball.getPosition().y >= 700 - (int)ballRadius*2 && ball.getPosition().y <= 700) && ((ball.getPosition().x <= player.getMiddle() + player.getWidth()/2) && (ball.getPosition().x >= player.getMiddle() + (player.getWidth()/2)*0.8))){
        ballMovement.y = -ballMovement.y;
        ballMovement.x = 10.f;
        canDestroy = true;
    }else if((ball.getPosition().y >= 700 - (int)ballRadius*2 && ball.getPosition().y <= 700) && ((ball.getPosition().x <= player.getMiddle() + (player.getWidth()/2)*0.8) && (ball.getPosition().x >= player.getMiddle() + (player.getWidth()/2)*0.5))){
        ballMovement.y = -ballMovement.y;
        ballMovement.x = 7.f;
        canDestroy = true;
    }else if((ball.getPosition().y >= 700 - (int)ballRadius*2 && ball.getPosition().y <= 700) && ((ball.getPosition().x <= player.getMiddle() + (player.getWidth()/2)*0.5) && (ball.getPosition().x >= player.getMiddle()))){
        ballMovement.y = -ballMovement.y;
        ballMovement.x = 2.f;
        canDestroy = true;
    }
}

void Ball::collisionWithBrick(Brick& brick){
    if(ball.getGlobalBounds().findIntersection(brick.GetBody()) && canDestroy == true){
        canDestroy = false;
        brick.Destroy();
        ballMovement.y = -ballMovement.y;
    }
}