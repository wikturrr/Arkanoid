#include "Game.h"

Game::Game() : window(sf::VideoMode({windowWidth, windowHeight}), "Arkanoid"){
    window.setFramerateLimit(60);
    playground.setFillColor({66, 60, 60});
    playground.setPosition({0.f,100.f});
    playground.setSize({playgroundWidth, PlaygroundHeight});
}

void Game::run(){
    Player player;
    std::vector<Brick> brick;
    Ball ball;

    for(int i=0; i<12; i++){
        for(int j=0; j<7; j++){
            brick.emplace_back(i*50.f, j*50.f+100.f);
        }
    }
    
    //------GAME-LOOP--------
    while(window.isOpen()){
        window.clear({77, 70, 70});
        while(std::optional event = window.pollEvent()){
            if(event->is<sf::Event::Closed>()){
                window.close();
            }
        }
        player.movement(window);
        ball.movement(window, player);

        window.draw(playground);
        ball.draw(window);
        player.draw(window);
        for(Brick& b: brick){
            b.draw(window);
            ball.collisionWithBrick(b);
        }
        window.display();
    }
}